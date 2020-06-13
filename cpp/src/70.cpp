#include <bits/stdc++.h>

int climbStairs(int n)
{
    std::vector<int> list = { 0, 1, 2 };
    for (int i = 3; i <= n; i++)
    {
        std::cout << i - 1 << "\t" << i - 2 << std::endl;
        std::cout << list[i - 1] << "\t" << list[i-2] << std::endl;

        list.push_back(list[i - 1] + list[i - 2]);
    }
    return list[n];
}

int main()
{
    int n = 44;
    std::cout << climbStairs(n) << std::endl;
}
