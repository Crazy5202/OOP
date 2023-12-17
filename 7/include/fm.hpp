#include <memory>
#include <shared_mutex>
#include <queue>
#include <chrono>
#include <thread>
#include "npc.hpp"
#include "observer.hpp"

using namespace std::chrono_literals;

struct FightEvent {
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};

class FightManager {
    std::queue<FightEvent> events;
    std::shared_mutex m_mtx;
    std::vector<Observer*> observers;
public:
    void add_event(const FightEvent& event);
    void attach(Observer* observer);
    void detach(Observer* observer);
    void notify(NPC* defender, NPC* attacker);
    void operator() (std::chrono::steady_clock::time_point start_time, std::shared_mutex* mtx);
};