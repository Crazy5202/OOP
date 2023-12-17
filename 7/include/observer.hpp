#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <shared_mutex>
#include "npc.hpp"

class Observer {
public:
    Observer() = default;
    virtual void announce(NPC* defender, NPC* attacker) = 0;
};

class ConsoleObserver: public Observer {
    std::shared_mutex* m_mtx;
public:
    ConsoleObserver(std::shared_mutex*);
    virtual void announce(NPC* defender, NPC* attacker);
};

class FileObserver: public Observer {
    std::unique_ptr<std::ostream> stream;
public:
    FileObserver(std::ofstream& out);
    virtual void announce(NPC* defender, NPC* attacker);
};