#include <iostream>
#include <list>
#include <map>
#include "Allocator.hpp"

//


int main(int argc, char **argv)
{

    std::map<int, int, std::less<int>,Allocator<std::pair<const int,int>>> my_map;

    my_map[1]=10;
    my_map[2]=20;
    my_map[3]=30;


    for(const auto& [k,v]: my_map)
        std::cout << k << "->" << v << std::endl;

    Allocator<int> allocator;
    int* ptr = allocator.allocate(1);
    ptr[0] = 100;
    std::cout << ptr[0];
    return 0;



}