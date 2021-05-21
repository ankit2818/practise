// P(n, k) = P(n-1, k) + k* P(n-1, k-1)
// https://www.geeksforgeeks.org/permutation-coefficient/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, int r)
{
    int fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = i * fact[i - 1];
    }
    return fact[n] / fact[n - r];
}

int main()
{

    // int t, n, r;
    // cin >> t;
    // while (t--)
    // {
    //     cin >> n >> r;
    //     cout << solve(n, r) << endl;
    // }

    cout << solve(10, 2) << endl;
    cout << solve(10, 3) << endl;
    cout << solve(10, 0) << endl;
    cout << solve(10, 1) << endl;
    cout << solve(10, 10) << endl;

    // P(10, 2) = 90 P(10, 3) = 720 P(10, 0) = 1 P(10, 1) = 10
    return 0;
}