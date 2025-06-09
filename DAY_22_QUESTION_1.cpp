// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> maxLen(n, vector<int>(m, 1));
        vector<vector<int>> queue;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                queue.push_back({matrix[i][j], i, j});
            }
        }
        sort(queue.begin(), queue.end());
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 1;
        for (int i = 0; i < queue.size(); i++)
        {
            for (auto &&di : dir)
            {
                int x = di[0] + queue[i][1], y = di[1] + queue[i][2];
                if (0 <= x && x < n && 0 <= y && y < m && matrix[x][y] > queue[i][0])
                {
                    maxLen[x][y] = max(maxLen[x][y], 1 + maxLen[queue[i][1]][queue[i][2]]);
                    ans = max(ans, maxLen[x][y]);
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