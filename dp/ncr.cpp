// C(n, k) = C(n-1, k-1) + C(n-1, k)
// C(n, 0) = C(n, n) = 1
// https://practice.geeksforgeeks.org/problems/ncr/0

#include <bits/stdc++.h>
using namespace std;

int solve(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;

    int fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = i * fact[i - 1];
    }
    return fact[n] / (fact[r] * fact[n - r]);
}

int main()
{

    cout << solve(10, 2) << endl;
    cout << solve(10, 3) << endl;
    cout << solve(10, 0) << endl;
    cout << solve(10, 1) << endl;
    cout << solve(10, 10) << endl;
    return 0;
}