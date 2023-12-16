#pragma once
#include "npc.hpp"

class Slaver: public NPC {
public:
    Slaver(const int& _x, const int& _y, const std::string& _name);

    virtual bool accept(NPC* attacker, const int& distance);
};