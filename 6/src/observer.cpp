#include "observer.hpp"
#include "npc.hpp"

void ConsoleObserver::announce(NPC* defender, NPC* attacker) {
    std::cout << "KILL: ";
    defender->print(std::cout);
    std::cout << " was killed by ";
    attacker->print(std::cout);
    std::cout << std::endl;
}

FileObserver::FileObserver(std::ofstream& _str) {
    _stream = std::make_unique<std::ofstream>(std::move(_str));
}

void FileObserver::announce(NPC* defender, NPC* attacker) {
    *_stream << "KILL: ";
    defender->print(*_stream);
    *_stream << " was killed by ";
    attacker->print(*_stream);
    *_stream << std::endl;
}