// https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll solve(ll post, ll color)
{
    // if (post <= 0 || color <= 0)
    //     return 0;
    // if (post == 1)
    //     return color;
    // if (color == 1)
    //     return 1;
    // return solve(post, color - 1) + solve(post - 1, color - 1) + solve(post - 1, color);

    ll dp[post + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = color;
    dp[2] = color * color;
    for (ll i = 3; i <= post; i++)
    {
        dp[i] = (color - 1) * ((dp[i - 1] + dp[i - 2]) % mod) % mod;
    }
    return dp[post];
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        ll n = rand() % 100000;
        ll k = rand() % 100;
        cout << n << ",\t" << k << ":\t" << solve(n, k) << endl;
    }
    return 0;
}