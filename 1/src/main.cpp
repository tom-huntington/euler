#include <range/v3/all.hpp>
#include <iostream>
#include <cstdlib>

int main()
{
    auto a = ranges::views::iota(1u, 1000u) 
        | ranges::views::filter([](auto b){ return (b % 5) == 0 || (b % 3) == 0; });
    std::cout << ranges::accumulate(a, 0);
    
}