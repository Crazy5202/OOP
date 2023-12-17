#include "npc.hpp"
#include "observer.hpp"
#include <vector>

class Fighters {
public:
    Fighters() = default;
    ~Fighters() = default;

    void load(std::string& filename);
    void save(std::string& filename) const;
    void add();
    void show() const;

    void attach(Observer* observer);
    void detach(Observer* observer);
    
    void set_distance(const int& _distance) {distance = _distance;};
    int get_distance() const {return distance;};

    void notify(NPC* defender, NPC* attacker);
    void fight();
private:
    std::vector<Observer*> observers;
    std::vector<std::shared_ptr<NPC>> flist;
    int distance = 10;
};