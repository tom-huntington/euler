#include <range/v3/all.hpp>
#include <iostream>

constexpr unsigned N = 100;
int main()
{
    auto numbers = ranges::views::iota(1u, N + 1);
    auto squares = numbers
        | ranges::views::transform(
            [](auto a) { return a*a;}
        );
    auto sum_of_squares = ranges::accumulate(squares, 0, std::plus{});
    auto sum = ranges::accumulate(numbers, 0, std::plus{});
    auto ans =  sum*sum - sum_of_squares;

    std::cout << "sum_of_squares " << sum_of_squares << " sum*sum " << sum*sum<< " ans " << ans << std::endl;


    return 0;
}