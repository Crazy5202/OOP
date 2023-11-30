#include "allocator.hpp"
#include "vector.hpp"
#include <iostream>
#include <map>
#include <vector>

int main() {
    std::vector<int, MyAllocator<int, 10>> vec;
    vec.push_back(10);
    vec.push_back(20);
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int,int>, 10>> my_map;
    my_map[1]=10;
    my_map[2]=20;
    my_map[3]=30;
    for(const auto& [k,v]: my_map) std::cout << k << "->" << v << std::endl;
    
    Vector<int> tester;
    tester.push_back(10);
    tester.push_back(20);
    std::cout << tester[0] << " " << tester[1] << std::endl;
    tester.clear();
    return 0;
}