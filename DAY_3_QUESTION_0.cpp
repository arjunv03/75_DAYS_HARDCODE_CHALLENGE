// https://leetcode.com/problems/dungeon-game/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dun)
    {
        int nrow = dun.size();
        int ncol = dun[0].size();
        vector<int> row(ncol + 1, INT_MAX);
        row[ncol - 1] = 1;
        int t;
        for (int i = nrow - 1; i >= 0; --i)
        {
            for (int j = ncol - 1; j >= 0; --j)
            {
                t = min(row[j], row[j + 1]) - dun[i][j];
                row[j] = max(t, 1);
            }
        }
        return row[0];
    }
};
int main()
{
    return 0;
}

// class Solution
// {
// public:
//     int helper(vector<vector<int>> &dungeon, int initalHealth)
//     {
//         int n = dungeon.size();
//         int m = dungeon[0].size();
//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));
//         dp[0][1] = initalHealth;
//         dp[1][0] = initalHealth;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 int a = (dp[i][j + 1] + dungeon[i][j] > 0) ? dp[i][j + 1] + dungeon[i][j] : 0;
//                 int b = (dp[i + 1][j] + dungeon[i][j] > 0) ? dp[i + 1][j] + dungeon[i][j] : 0;
//                 if (max(a, b) != 0)
//                 {
//                     dp[i + 1][j + 1] = max(a, b);
//                 }
//             }
//         }
//         for (auto &&i : dp)
//         {
//             for (auto &&j : i)
//             {
//                 cout << j << ' ';
//             }
//             cout << endl;
//         }

//         return (dp[n][m] > 0);
//     }
//     int calculateMinimumHP(vector<vector<int>> &dungeon)
//     {
//         int n = dungeon.size();
//         int lo = 1;
//         int hi = 1e9;
//         int ans = 1e9;
//         while (lo <= hi)
//         {
//             int mid = (lo + hi) / 2;
//                 cout<<mid<<endl;
//             if (helper(dungeon, mid))
//             {
//                 ans = mid;
//                 hi = mid - 1;
//             }
//             else
//             {
//                 lo = mid + 1;
//             }
//         }
//         return ans;
//     }
// };