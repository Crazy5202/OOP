#pragma once
#include <iostream>
#include <fstream>
#include <memory>

class NPC;

class Observer {
public:
    Observer() = default;
    virtual void announce(NPC* defender, NPC* attacker) = 0;
};

class ConsoleObserver: public Observer {
public:
    ConsoleObserver() = default;
    virtual void announce(NPC* defender, NPC* attacker);
};

class FileObserver: public Observer {
    std::unique_ptr<std::ostream> _stream;
public:
    FileObserver(std::ofstream& out);
    virtual void announce(NPC* defender, NPC* attacker);
};