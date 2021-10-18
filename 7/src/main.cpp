#include <range/v3/all.hpp>
#include <iostream>

bool is_prime(unsigned i)
{
    if (i==2)
        return true;
    else if (i==1)
        return false;

    auto s = std::ceil(std::sqrt(i));
    //std::cout << s << std::endl;
    for (auto j : ranges::views::iota(2u,s+1))
    {
        //std::cout << "j " << j << " i " << i << std::endl;
        if (i%j==0)
            return false;
    }
    return true;
}

constexpr unsigned N = 10'001;//6;
int main()
{
    //std::cout << is_prime(25) << std::endl;
    auto a = ranges::views::iota(2u, ranges::unreachable)
        | ranges::views::filter(&is_prime)
        | ranges::views::take(N);
    std::cout << a << std::endl;

}