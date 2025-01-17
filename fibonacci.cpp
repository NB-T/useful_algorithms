#include <cmath>
#include <fstream>
#include <iostream>

#include "nbtlog.hpp"

long long int FibDyPrIterative(int n)
{
    if (n <= 1)
    {
        return n;
    }

    long long int* dp = new long long int[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    long long int r = dp[n];
    delete[] dp;
    return r;
}

long long int FibRecursive(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return FibRecursive(n - 1) + FibRecursive(n - 2);
}

long long int FibClosedForm(int n)
{
    ++n;
    return (1 / std::sqrt(5)) * std::pow(((1 + std::sqrt(5)) / 2), n) - (1 / std::sqrt(5)) * std::pow(((1 - std::sqrt(5)) / 2), n);
}

int main(int argc, char* argv[])
{
    int n = std::stoi(argv[1]);
    std::ofstream("fibdypriterative.dat");
    for (int i = 0; i < 1; ++i)
    {
        auto start = nbtlog::timestamp();
        int n = FibClosedForm(n);
        auto end = nbtlog::timestamp();
        nbtlog::log(std::to_string(n - FibDyPrIterative(n)), start, end);
    }

    return EXIT_SUCCESS;
}
