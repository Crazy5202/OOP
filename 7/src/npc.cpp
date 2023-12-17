#include "npc.hpp"
#include <iostream>
#include <cmath>

bool NPC::is_close(const NPC& other) const {
    return std::pow(x - other.x, 2) + std::pow(y - other.y, 2) <= std::pow(other.get_distance(), 2);
}

void NPC::print(std::ostream& out) const {
    out << type << " " << name << " " << x << " " << y;
}