// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mine;
int row, col, maxGold = 0;

int getMaxGold(int r, int c)
{
    if (r >= row || r < 0 || c >= col)
        return 0;

    return mine[r][c] + max(getMaxGold(r - 1, c + 1), max(getMaxGold(r, c + 1), getMaxGold(r + 1, c + 1)));
}

int solve()
{
    for (int i = 0; i < row; i++)
    {
        int getMax = getMaxGold(i, 0);
        // cout << getMax << endl;
        if (getMax > maxGold)
            maxGold = getMax;
    }
    return maxGold;
}

int main()
{

    int r, c, i, j;
    cin >> row >> col;

    for (i = 0; i < row; i++)
    {
        vector<int> temp = {};
        for (j = 0; j < col; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        mine.push_back(temp);
    }
    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < col; j++)
    //     {
    //         cout << mine[i][j] << "\t";
    //     }
    //     cout << endl;
    // }
    cout << solve();
}