#include "slaver.hpp"
#include "druid.hpp"
#include "orc.hpp"

Druid::Druid(const int& _x, const int& _y, const std::string& _name) {
    type = "Druid";
    x = _x;
    y = _y;
    name = _name;
    alive = true;
}

bool Druid::accept(NPC* attacker, const int& distance) {
    bool killed = false;
    if (alive && (attacker->get_type() == "Orc" || attacker->get_type() == "Slaver")) {
        if (is_close(*attacker, distance)) { 
            alive = false;
            killed = true;
        }
    }
    return killed;
}