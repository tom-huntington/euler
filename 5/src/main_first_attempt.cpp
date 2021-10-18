#include <range/v3/all.hpp>
#include <iostream>
#include <cppcoro/generator.hpp>
#include "../../zip_longest.hpp"

//template<unsigned N>
cppcoro::generator<const /*std::pair<unsigned,*/unsigned/*>*/> prime_factorization(unsigned N)
{
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
        co_yield count;
        i++;
    }
    //while (true)
    //    co_yield {i++, 0};
}


constexpr unsigned N = 20; //10;
int main()
{
    auto a = prime_factorization(2) | ranges::to_vector;
    //auto b = prime_factorization(1) | ranges::to_vector;
    //auto c = prime_factorization(1) | ranges::to_vector;
    std::vector<unsigned> b;
    //auto b = 
    std::vector<unsigned> c;
    
    //auto b = prime_factorization<1>() | ranges::to_vector;
    //auto a1 = ranges::views::iota(2) | ranges::views::take(30) | ranges::to_vector;
    //auto c =;
    
    for (auto i: ranges::views::iota(3u,N+1u))// prime_factorization<30>())
    {
        c.resize(0);
        b = prime_factorization(i) | ranges::to_vector;
        for (auto&& [u,v] : zip_longest(a,b) )
        {
            c.push_back(std::max(u,v));
        }
        
        //auto z = c  | ranges::views::all;
        //std::cout << z << std::endl;
        a = std::move(c);
        //std::cout << "hi\n";
        //std::cout << '(' << i << ',' << j << ',' << k << ')' << std::endl;
        //std::cout << '(' << j.first << ',' << j.second << ')' << std::endl;
    }
    auto z = a  | ranges::views::all;
    std::cout << z << std::endl;
    auto zz = ranges::views::zip(ranges::views::iota(2, ranges::unreachable), a)
        | ranges::views::filter([](auto a){return a.second !=0;});
    for (auto ii : zz)
    {
        std::cout << '(' << ii.first << ',' << ii.second << ')' << std::endl;

    }
    auto zzz = zz
            | ranges::views::transform(
        [](auto a){ return std::pow(a.first, a.second);})
            //| ranges::views::filter([](auto a){return a !=0;})
            ;
    auto ans = ranges::accumulate(zzz, 1, std::multiplies{});//[](int a, int b){return a * b;});
    std::cout << zzz << std::endl<< ans<< std::endl;
    



    //float a[]{ 1.2, 2.3, 3.4, 4.5 };
    //std::vector<int> b{ 1, 2, 3, 4, 5 };
    //std::array<double, 3> c{ 1.1, 2.2, 3.3 };
    //std::vector<std::string> d{ "a", "b", "c" };
//
    //for (auto&& [i, j, k, l] : zip_longest(a, b, c, d)) {
    //    std::cout << i << " - " << j << " - " << k << " - " << l << std::endl;
    //}



    //auto const v1 = std::vector<int> {4,2,7,3};
    //auto const v2 = std::vector<int> {3,2,1};
    //auto rng = ranges::views::zip_with(
    //            [](int a, int b = 0){return a + b;}, v1, v2);
    //std::cout << b << std::endl;

    return 0;
}