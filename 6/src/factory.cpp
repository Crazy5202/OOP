#include "factory.hpp"
#include "slaver.hpp"
#include "druid.hpp"
#include "orc.hpp"
#include <memory>
#include <iostream>

std::shared_ptr<NPC> factory(std::istream& in) {
    std::string type, name;
    int x, y;
    in >> type >> name >> x >> y;
    std::shared_ptr<NPC> res;
    if (type == "Slaver") {
        res = std::make_shared<Slaver>(x, y, name);
    }
    else if (type == "Druid") {
        res = std::make_shared<Druid>(x, y, name);
    }
    else if (type == "Orc") {
        res = std::make_shared<Orc>(x, y, name);
    }
    else if (type != "") {
        std::cerr << "Unknown type" << std::endl;
    }
    return res;
}