#include "druid.hpp"

Druid::Druid(const int& _x, const int& _y, const std::string& _name) {
    type = "Druid";
    x = _x;
    y = _y;
    name = _name;
    alive = true;
    kill_distance = 10;
}

bool Druid::accept(NPC* attacker) {
    bool killed = false;
    if (alive && (attacker->get_type() == "Orc" || attacker->get_type() == "Slaver")) {
        if (is_close(*attacker)) { 
            int my_d6 = std::rand()%6;
            int enemy_d6 = std::rand()%6;
            if (enemy_d6 > my_d6) {
                alive = false;
                killed = true;
            }
        }
    }
    return killed;
}

void Druid::move(const int& _x, const int& _y) {
    x = std::abs(x + std::rand()%10-5) % _x;
    y = std::abs(y + std::rand()%10-5) % _y; 
}

char Druid::symbol() const {
    return alive ? 'D' : '@';
}