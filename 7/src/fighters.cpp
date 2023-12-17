#include "fighters.hpp"
#include "factory.hpp"
#include <algorithm>

void Fighters::load(std::string& filename) {
    std::ifstream file_loader;
    file_loader.open(filename);
    while (file_loader) {
        auto tmp = factory(file_loader);
        if (tmp) flist.push_back(tmp);
    }
    file_loader.close();
}

void Fighters::save(std::string& filename) const {
    std::ofstream file_writer;
    file_writer.open(filename);
    for (auto& elem: flist) {
        elem->print(file_writer);
    }
    file_writer.close();
}

void Fighters::add() {
    flist.push_back(factory(std::cin));
}

void Fighters::show() const {
    for (auto& elem: flist) {
        elem->print(std::cout);
        std::cout << std::endl;
    }
}

void Fighters::attach(Observer* observer) {
    fm.attach(observer);
}

void Fighters::detach(Observer* observer) {
    fm.detach(observer);
}

void Fighters::fight() {
    auto start_time = std::chrono::steady_clock::now();

    std::thread fight_thread(std::ref(fm), start_time, std::ref(data_mtx));

    std::thread move_thread([this, start_time] () {
        while (std::chrono::steady_clock::now() - start_time < 10s) {
            {
                std::lock_guard<std::shared_mutex> movelock(data_mtx);
                for (auto npc : flist) {
                    if (npc->is_alive())
                        npc->move(max_x, max_y);
                }
            }
            {
                std::shared_lock<std::shared_mutex> readlock(data_mtx);
                for (auto attacker : flist) {
                    for (auto defender : flist) {
                        if (attacker==defender) continue;
                        if (attacker->is_alive() && defender->is_alive()) {
                            if (attacker->is_close(*defender))
                                fm.add_event({attacker, defender});
                        }
                    }
                }
                
            }
            std::this_thread::sleep_for(1s);
        }
    });

    while (std::chrono::steady_clock::now() - start_time < 10s) {
        std::vector<std::vector<char>> field(max_y, std::vector<char>(max_x, '.'));
        {
            std::shared_lock<std::shared_mutex> readlock(data_mtx);
            for (auto npc : flist) {
                auto [x, y] = npc->get_cord();
                field[y][x] = npc->symbol();
            }
        }
        {
            std::lock_guard<std::shared_mutex> printlock(io_mtx);
            for (int i = 0; i < field.size(); ++i) {
                for (int j = 0; j < field[i].size(); ++j) {
                    std::cout << field[i][j];
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(1s);
    }

    move_thread.join();
    fight_thread.join();

    auto condition = [](std::shared_ptr<NPC> obj) {return !obj.get()->is_alive();};
    flist.erase(std::remove_if(flist.begin(), flist.end(), condition), flist.end());
}