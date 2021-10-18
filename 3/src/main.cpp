#include <range/v3/all.hpp>
#include <iostream>
#include <cppcoro/generator.hpp>

constexpr uint64_t N = 600851475143;//13195;
bool is_prime(unsigned i)
{
    auto s = std::ceil(std::sqrt(i));
    //std::cout << s << std::endl;
    for (auto j : ranges::views::iota(2u,s+1))
    {
      ///std::cout << j << std::endl;
        if (i%j==0)
            return false;
    }
    return true;
}

template <uint64_t N>
cppcoro::generator<const std::uint64_t> prime_factors()
{
  uint64_t remaining = N;
  unsigned i = 1;
  //for (auto i : ranges::views::iota(2u, N / 2))//ranges::unreachable
  while (i++ < remaining)
        {
          //std::cout << i << std::endl;
            if (remaining % i == 0)
            {
                if (is_prime(i))
                {
                    remaining /= i;
                    co_yield i;
                }
            }
        }
}


int main()
{
    for (auto i : prime_factors<N>())
    {
      std::cout << i << std::endl;
    }
    //is_prime(13);
    //auto factors = ranges::generate(
    //    [](){ 
    //        for (auto i : ranges::views::iota(2u, ranges::unreachable))
    //        {
    //            if (N % i == 0)
    //            {
    //                if (is_prime(i))
    //                    return N / 2;
    //            }
    //        }
    //    }
    //);

    //std::cout << factors | ranges::views::take(1);
    return 0;
}