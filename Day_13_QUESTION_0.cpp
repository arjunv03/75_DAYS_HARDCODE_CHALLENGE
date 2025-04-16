// https://leetcode.com/problems/swim-in-rising-water/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    vector<vector<int>> dis = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool helper(int maxHt, vector<vector<int>> &grid)
    {
        if (maxHt < grid[0][0])
        {
            return false;
        }
        int n = grid.size();
        vector<vector<bool>> isVis(n, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> &tp = q.front();
                if (isVis[tp.first][tp.second] == 0)
                {
                    isVis[tp.first][tp.second] = 1;
                    for (auto &&idx : dis)
                    {
                        int x = tp.first + idx[0], y = tp.second + idx[1];
                        if (0 <= x && x < n && 0 <= y && y < n && (isVis[x][y] == 0) && grid[x][y] <= maxHt)
                        {
                            q.push({x, y});
                        }
                    }
                }
                q.pop();
            }
        }
        return isVis[n - 1][n - 1];
    }
    int swimInWater(vector<vector<int>> &grid)
    {
        int lo = 0, hi = 1e9, ans = 1e9;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (helper(mid, grid))
            {
                ans = min(ans, mid);
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
int main()
{
    
    return 0;
}