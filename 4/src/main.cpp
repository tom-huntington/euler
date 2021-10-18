#include <range/v3/all.hpp>
#include <iostream>

int main()
{
    std::string s;
    constexpr uint64_t N = 999;//99;
    constexpr uint64_t M = 100;//10;
    auto a = ranges::views::iota(1u, N * N + 1)
        | ranges::views::reverse
        | ranges::views::filter(
            [&s](auto a){
                s = std::to_string(a);
                return ranges::equal(s, s | ranges::views::reverse);
            }
        )
        | ranges::views::filter(
            [](auto a){
                for (auto i : ranges::views::iota(M, N + 1))
                    if (a % i == 0 && a / i >= M && a/i <= N)
                        return true;
                
                return false;
            }
        )
        | ranges::views::take(5);
    //std::string s = "1001";
    //auto r = s | ranges::views::reverse;
    //std::cout << r << std::endl;
    //std::cout << "equal ? " << ranges::equal(r, s) << std::endl;
    
    std::cout << a << std::endl;
    return 0;
}