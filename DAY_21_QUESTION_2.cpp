// https://leetcode.com/problems/making-a-large-island/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    unordered_map<int, int> island;
    vector<vector<int>> grid;
    int helper(int i, int j, int islandId)
    {
        if (0 <= i && i < grid.size() && 0 <= j && j < grid[0].size() && grid[i][j] == 1)
        {
            grid[i][j] = islandId;
            island[islandId] = 1 + helper(i, j + 1, islandId) + helper(i, j - 1, islandId) + helper(i + 1, j, islandId) + helper(i - 1, j, islandId);
            return island[islandId];
        }
        return 0;
    }
    int largestIsland(vector<vector<int>> &ip)
    {
        island.clear();
        this->grid = ip;
        int islandId = 2;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (helper(i, j, islandId))
                {
                    islandId++;
                }
            }
        }
        if (island.size() == 0)
        {
            return 1;
        }
        if (island.size() == 1)
        {
            return min(island[islandId - 1] + 1, int(grid.size() * grid[0].size()));
        }
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 1;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    int size = 1;
                    set<int> connectedIsland;
                    for (auto &&di : dir)
                    {
                        int x = di[0] + i, y = di[1] + j;
                        if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[x][y] != 0)
                        {
                            connectedIsland.insert(grid[x][y]);
                        }
                    }
                    for (auto &&iland : connectedIsland)
                    {
                        size += island[iland];
                    }
                    ans = max(ans, size);
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