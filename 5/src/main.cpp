#include <range/v3/all.hpp>
#include <iostream>
//#include <cppcoro/generator.hpp>
#include "../../zip_longest.hpp"

//template<unsigned N>

std::vector<unsigned> prime_factorization(unsigned N)
{
    std::vector<unsigned> factors;
    unsigned remaining = N;
    unsigned i = 2;
    while (remaining > 1)
    {
        unsigned count = 0;
        while ( remaining % i == 0)
            {
                remaining /= i;
                count++;
            }
        factors.push_back(count);
        //auto a = factors | ranges::views::all;
        //std::cout << a << std::endl;
        i++;
    }
    return std::move(factors);
    //while (true)
    //    co_yield {i++, 0};
}

//cppcoro::generator<const /*std::pair<unsigned,*/unsigned/*>*/> 

constexpr unsigned N = 20;//10;
int main()
{
    //prime_factorization(4);
    auto range_of_factorizations = ranges::views::iota(2u,N+1)
        | ranges::views::transform(
            [](auto a){ return prime_factorization(a);}
        )
        //| ranges::to_vector
        ;
//
    //auto a = range_of_factorizations | ranges::views::all;
    for (auto v : range_of_factorizations)// ranges::views::iota(2u,N+1))
    {
        auto b = v | ranges::views::all;
        
        std::cout << b << std::endl;
    }
    auto z = ranges::accumulate(range_of_factorizations, std::vector<unsigned>{}, 
        [](std::vector<unsigned> a, std::vector<unsigned> b) -> std::vector<unsigned>
        {
            //return b;
            std::vector<unsigned> c;
            for (auto&& [u,v] : zip_longest(a,b) )
            {
                //c.push_back(1);
                c.push_back(std::max(u,v));
            }
            return std::move(c);

        }
        );

    auto zz = z | ranges::views::all;
    std::cout << "-----------------" << std::endl << zz << std::endl;
    auto w = ranges::views::zip_with(
        [](auto a, auto b)  
        {
            return pow(a,b);
        },
        ranges::views::iota(2u,ranges::unreachable), z);
    std::cout << w << std::endl;
    auto ans = ranges::accumulate(w, 1, std::multiplies{});
    std::cout << ans <<std::endl;
//
    //auto a = prime_factorization()

}