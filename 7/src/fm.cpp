#include "fm.hpp"
#include <algorithm>

void FightManager::attach(Observer* observer) {
    observers.push_back(observer);
}

void FightManager::detach(Observer* observer) {
    observers.erase(std::find(observers.begin(), observers.end(), observer));
}

void FightManager::notify(NPC* defender, NPC* attacker) {
    for (auto& elem: observers) {
        elem->announce(defender,attacker);
    }
}

void FightManager::add_event(const FightEvent& event) {
    std::lock_guard<std::shared_mutex> addlock(m_mtx);
    events.push(event);
}

void FightManager::operator() (std::chrono::steady_clock::time_point start_time, std::shared_mutex& mtx) {
    while (std::chrono::steady_clock::now() - start_time < 10s) {
        if (!events.empty()) {
            FightEvent current_fight;
            {
                std::lock_guard<std::shared_mutex> poplock(m_mtx);
                current_fight = events.front();
                events.pop();
            }
            {
                std::lock_guard<std::shared_mutex> fightlock(mtx);
                if (current_fight.defender->is_alive() && current_fight.attacker->is_alive()) {
                    if (current_fight.defender->accept(current_fight.attacker.get())) notify(current_fight.defender.get(), current_fight.attacker.get());
                    if (current_fight.attacker->accept(current_fight.defender.get())) notify(current_fight.attacker.get(), current_fight.defender.get());
                }
            }
        }
        else {
            std::this_thread::sleep_for(100ms);
        }
    }
}