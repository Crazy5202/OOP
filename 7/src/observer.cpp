#include "observer.hpp"
#include "npc.hpp"
#include <chrono>
#include <ctime>

ConsoleObserver::ConsoleObserver(std::shared_mutex* mtx): m_mtx(mtx) {}

void ConsoleObserver::announce(NPC* defender, NPC* attacker) {
    std::lock_guard<std::shared_mutex> printlock(*m_mtx);
    std::cout << "KILL: ";
    defender->print(std::cout);
    std::cout << " was killed by ";
    attacker->print(std::cout);
    std::cout << std::endl;
}

FileObserver::FileObserver(std::ofstream& _str) {
    stream = std::make_unique<std::ofstream>(std::move(_str));
}

void FileObserver::announce(NPC* defender, NPC* attacker) {
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct std::tm* localTime = std::localtime(&currentTime);
    *stream << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << " ";
    *stream << "KILL: ";
    defender->print(*stream);
    *stream << " was killed by ";
    attacker->print(*stream);
    *stream << std::endl;
}