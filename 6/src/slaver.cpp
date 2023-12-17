#include "slaver.hpp"
#include "druid.hpp"
#include "orc.hpp"

Slaver::Slaver(const int& _x, const int& _y, const std::string& _name) {
    type = "Slaver";
    x = _x;
    y = _y;
    name = _name;
    alive = true;
}

bool Slaver::accept(NPC* attacker, const int& distance) {
    bool killed = false;
    if (alive && attacker->get_type() == "Orc") {
        if (is_close(*attacker, distance)) {
            alive = false;
            killed = true;
        }
    }
    return killed;
}