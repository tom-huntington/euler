add_executable(even_fibonacci_numbers src/main.cpp)
target_include_directories(even_fibonacci_numbers PUBLIC $ENV{CPPCORO_INCLUDE})
target_link_libraries(even_fibonacci_numbers range-v3 cppcoro)#$ENV{CPPCORO_LIBS})