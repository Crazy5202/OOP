#include "slaver.hpp"

Slaver::Slaver(const int& _x, const int& _y, const std::string& _name) {
    type = "Slaver";
    x = _x;
    y = _y;
    name = _name;
    alive = true;
    kill_distance = 10;
}

bool Slaver::accept(NPC* attacker) {
    bool killed = false;
    if (alive && attacker->get_type() == "Orc") {
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

void Slaver::move(const int& _x, const int& _y) {
    x = std::abs(x + std::rand()%20-10) % _x;
    y = std::abs(y + std::rand()%20-10) % _y; 
}

char Slaver::symbol() const {
    return alive ? 'S' : '@';
}