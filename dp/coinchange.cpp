// https://practice.geeksforgeeks.org/problems/coin-change2448/1

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll arr[], ll len, ll val)
{
    ll dp[len][val + 1], i, j;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (i = arr[0]; i <= val; i += arr[0])
        dp[0][i] = 1;

    for (j = 1; j < len; j++)
        dp[j][0] = 1;
    for (i = 1; i < len; i++)
    {
        for (j = 1; j <= val; j++)
        {
            if (j < arr[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i]];
        }
    }
    return dp[len - 1][val];
}

int main()
{
    ll arr[] = {2, 5, 3, 6};

    cout << solve(arr, 4, 10);

    return 0;
}