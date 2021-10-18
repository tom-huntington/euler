#include <range/v3/all.hpp>
#include <iostream>

#include <cppcoro/generator.hpp>

unsigned add_if_even(unsigned i)
{
    if (i%2==0)
    {
        return i;
    }
    return 0;
}
 
int main()
{
    auto fib = ranges::views::generate(
        [p=std::tuple{0u,1u,0u,0u}]() mutable {
            ///auto a = std::pair{p.second, p.first+p.second};
            auto [a,b,sum, sum_even] = p;

            p = {b,a+b,sum+a, sum_even + add_if_even(a)};

            return std::tuple{a,sum+a, sum_even + add_if_even(a)};}
    );

    auto out = fib | ranges::views::take_while([](auto i){return std::get<0/*1*/>(i) < 4'000'000;}) ;// << std::endl;
    //auto out2 = out | ranges::views::transform([](auto tu){return std::get<0>(tu);});
    //auto out3 = out | ranges::views::transform([](auto tu){return std::get<1>(tu);});
    //std::cout << out2 << std::endl << out3 << std::endl << out4 << std::endl;
    //auto ans = out | ranges::views::reverse;// | ranges::views::take(1);
    
    
    auto out4 = out | ranges::views::transform([](auto tu){return std::get<2>(tu);}) | ranges::to_vector ;
    //auto out5 = out | ranges::views::transform([](auto tu){return std::get<2>(tu);});
    //auto out4 = ranges::max(out5);
    std::cout << out4.back() <<std::endl;
    return 0;
}
