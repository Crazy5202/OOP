#include <vector>
#include "npc.hpp"
#include "observer.hpp"
#include "fm.hpp"

class Fighters {
public:
    Fighters(std::shared_mutex* data_mtx, std::shared_mutex* io_mtx);
    ~Fighters() = default;

    void load(std::string& filename);
    void save(std::string& filename) const;
    void add();
    void show() const;

    void attach(Observer* observer);
    void detach(Observer* observer);
    
    void fight();
private:
    int max_x = 30;
    int max_y = 30;
    std::shared_mutex* io_mtx;
    std::shared_mutex* data_mtx;
    FightManager fm;
    std::vector<std::shared_ptr<NPC>> flist;
};