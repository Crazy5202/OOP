#include "orc.hpp"
#include "druid.hpp"
#include "orc.hpp"

Orc::Orc(const int& _x, const int& _y, const std::string& _name) {
    type = "Orc";
    x = _x;
    y = _y;
    name = _name;
    alive = true;
}

bool Orc::accept(NPC* attacker, const int& distance) {
    if (alive && attacker->get_type() == "Orc") {
        if (is_close(*attacker, distance)) { 
            alive = false;
            return true;
        }
    }
    return false;
}