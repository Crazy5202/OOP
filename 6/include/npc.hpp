#pragma once
#include <string>

class NPC {
protected:
    std::string type;
    std::string name;
    int x;
    int y;
    bool alive;
public:
    NPC() = default;
    ~NPC() = default;
    
    virtual bool accept(NPC* attacker, const int& distance) = 0;
    void print(std::ostream& out) const;

    bool is_close(const NPC& other, const int& distance) const;
    bool is_dead() const {return !alive;};

    std::string get_type() const {return type;};
};