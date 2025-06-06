// https://leetcode.com/problems/cherry-pickup-ii/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        int ans = 0;
        for (int gdRow = 1; gdRow < m; gdRow++)
        {
            for (int robACol = 0; robACol < n; robACol++)
            {
                for (int robBCol = robACol + 1; robBCol < n; robBCol++)
                {
                    for (int prevRobACol = robACol - 1; prevRobACol <= robACol + 1; prevRobACol++)
                    {
                        for (int prevRobBCol = robBCol - 1; prevRobBCol <= robBCol + 1; prevRobBCol++)
                        {
                            if (0 <= prevRobACol && prevRobACol < n && 0 <= prevRobBCol && prevRobBCol < n)
                            {
                                int prev = dp[gdRow - 1][prevRobACol][prevRobBCol];
                                if (prev != -1)
                                {
                                    dp[gdRow][robACol][robBCol] = max(dp[gdRow][robACol][robBCol], prev + grid[gdRow][robACol] + (robACol != robBCol ? grid[gdRow][robBCol] : 0));
                                }
                            }
                        }
                    }
                    ans = max(ans, dp[gdRow][robACol][robBCol]);
                }
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}
