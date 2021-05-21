// https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// int compareThreeNumbers(int a, int b, int c)
// {
//     if (a > b && a > c)
//         return a;
//     if (b > c)
//         return b;
//     return c;
// }

int solve(int n, int x, int y, int z)
{

    ll minimum;
    if (x < y && x < z)
        minimum = x;
    if (y < x && y < z)
        minimum = y;
    if (z < y && z < x)
        minimum = z;

    if (minimum != 0 && n % minimum == 0)
        return (n / minimum);

    ll dp[n + 1];
    for (ll i = 1; i <= n; i++)
        dp[i] = INT_MIN;
    dp[0] = 0;
    for (ll i = 1; i <= n; i++)
    {

        if (i - x >= 0 && dp[i] < 1 + dp[i - x])
        {
            dp[i] = 1 + dp[i - x];
        }
        if (i - y >= 0 && dp[i] < 1 + dp[i - y])
        {
            dp[i] = 1 + dp[i - y];
        }
        if (i - z >= 0 && dp[i] < 1 + dp[i - z])
        {
            dp[i] = 1 + dp[i - z];
        }
    }
    if (dp[n] > 0)
        return dp[n];
    return 0;

    // if (len <= 0)
    //     return 0;
    // if (len < x && len < y && len < z)
    //     return 0;
    // return 1 + compareThreeNumbers(solve(len - x, x, y, z), solve(len - y, x, y, z), solve(len - z, x, y, z));
}

int main()
{

    int len, x, y, z;
    while (true)
    {
        cin >> len >> x >> y >> z;
        cout << solve(len, x, y, z) << endl;
    }
}