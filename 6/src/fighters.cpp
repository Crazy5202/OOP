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
    observers.push_back(observer);
}

void Fighters::detach(Observer* observer) {
    observers.erase(std::find(observers.begin(), observers.end(), observer));
}

void Fighters::notify(NPC* defender, NPC* attacker) {
    for (auto& elem: observers) {
        elem->announce(defender,attacker);
    }
}

void Fighters::fight() {
    for (auto it1 = flist.begin(); it1!=flist.end(); ++it1) {
        for (auto it2 = flist.begin(); it2!=flist.end(); ++it2) {
            if (it1==it2) continue;
            bool status = (*it1)->accept((*it2).get(), distance);
            if (status) {
                notify((*it1).get(), (*it2).get());
            }
        }
    }
    auto condition = [](std::shared_ptr<NPC> obj) {return obj.get()->is_dead();};
    flist.erase(std::remove_if(flist.begin(), flist.end(), condition), flist.end());
}