// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1

/*
friends         pairs
0               0
1               1
2               2
3               4
4               10
5               26
6               

dp[i] = dp[i-1] + (i-1) * dp[i-2]
dp[3] = dp[2] + (2) * dp[1]
dp[3] = 4
dp[4] = dp[3] + (3) * dp[2]
dp[4] = 4 + (3) * 2
dp[4] = 10
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll solve(ll n)
{
    ll dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (ll i = 3; i <= n; i++)
    {
        dp[i] = ((dp[i - 1] % mod) + (((i - 1) % mod) * (dp[i - 2] % mod)) % mod) % mod;
    }
    return dp[n];
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
}
