#pragma once
#include <string>

class NPC {
protected:
    std::string type;
    std::string name;
    int x;
    int y;
    int kill_distance;
    bool alive;
public:
    NPC() = default;
    ~NPC() = default;
    
    virtual bool accept(NPC* attacker) = 0;
    virtual char symbol() const = 0;
    virtual void move(const int& _x, const int& _y) = 0;

    void print(std::ostream& out) const;

    bool is_close(const NPC& other) const;

    bool is_alive() const {return alive;};
    std::string get_type() const {return type;};
    std::pair<int,int> get_cord() const {return {x,y};};
    int get_distance() const {return kill_distance;};
};