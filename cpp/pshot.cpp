// https://www.codechef.com/LRNDSA02/problems/PSHOT

#include <bits/stdc++.h>
using namespace std;
#define ll long long
/* Test case
2
3
1 0 1 0 1 1
3
1 0 0 0 0 1
*/
void solve(ll arr[], ll n)
{
    ll sum = 0;
    ll i = 0;
    for (i = 0; i < 2 * n; i += 2)
    {
        sum += (arr[i] - arr[i + 1]);
    }

    cout << sum << endl;
}

int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i)
    {
        ll n;
        cin >> n;
        ll arr[2 * n];

        for (ll j = 0; j < 2 * n; ++j)
        {
            cin >> arr[j];
        }
        solve(arr, n);
    }
    return 0;
}
