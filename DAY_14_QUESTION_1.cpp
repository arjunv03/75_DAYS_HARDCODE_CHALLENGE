// https://leetcode.com/problems/swim-in-rising-water/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &isVis, int curr, int i, int j)
    {
        if (0 > i || i >= grid.size() || 0 > j || j >= grid[0].size() || (grid[i][j] > curr) || isVis[i][j])
        {
            return;
        }
        isVis[i][j] = 1;
        dfs(grid, isVis, curr, i + 1, j);
        dfs(grid, isVis, curr, i - 1, j);
        dfs(grid, isVis, curr, i, j + 1);
        dfs(grid, isVis, curr, i, j - 1);
    }
    int swimInWater(vector<vector<int>> grid)
    {
        int lo = 0, hi = 1e4, ans = 1e4;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            vector<vector<bool>> isVis(grid.size(), vector<bool>(grid[0].size(), 0));
            dfs(grid, isVis, mid, 0, 0);
            if (isVis[grid.size() - 1][grid[0].size() - 1])
            {
                cout << ans << endl;
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = lo + 1;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}