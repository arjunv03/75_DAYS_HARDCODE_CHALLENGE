// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1)
        {
            return -1;
        }
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> isVis(n, vector<bool>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        while (!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();
            if (curr[1] == n - 1 && curr[2] == m - 1)
            {
                return curr[0];
            }
            if (!isVis[curr[1]][curr[2]])
            {
                for (auto &di : dir)
                {
                    int i = curr[1] + di[0], j = curr[2] + di[1];
                    if (0 <= i && i < isVis.size() && 0 <= j && j < isVis[0].size() && !isVis[i][j])
                    {
                        int waitTime = ((grid[i][j] - curr[0]) % 2 == 0) ? 1 : 0;
                        int nextTime = max(grid[i][j] + waitTime, curr[0] + 1);
                        pq.push({nextTime, i, j});
                    }
                }
            }
            isVis[curr[1]][curr[2]] = true;
        }
        return -1;
    }
};
int main()
{
    return 0;
}