#pragma once
#include "npc.hpp"

class Orc: public NPC {
public:
    Orc(const int& _x, const int& _y, const std::string& _name);

    virtual bool accept(NPC* attacker);
    virtual char symbol() const;
    virtual void move(const int& _x, const int& _y);
};