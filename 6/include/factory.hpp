#include <memory>
#include "npc.hpp"

std::shared_ptr<NPC> factory(std::istream& in);
std::shared_ptr<NPC> factory(const std::string& type, const std::string& name, const int& x, const int& y);