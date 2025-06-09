// https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    bool hasValidPath(vector<vector<char>> &grid)
    {
        if (grid[0][0] == ')')
        {
            return 0;
        }
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> dpCanMakeSum(n, vector<vector<bool>>(m, vector<bool>(101, 0)));
        dpCanMakeSum[0][0][1] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = ((grid[i][j] == '(') ? 1 : -1);
                for (int k = 0; k < 101; k++)
                {
                    if (i - 1 >= 0 && dpCanMakeSum[i - 1][j][k] && 0 <= sum + k && sum + k < 101)
                    {
                        dpCanMakeSum[i][j][sum + k] = 1;
                    }
                    if (j - 1 >= 0 && dpCanMakeSum[i][j - 1][k] && 0 <= sum + k && sum + k < 101)
                    {
                        dpCanMakeSum[i][j][sum + k] = 1;
                    }
                }
            }
        }
        return dpCanMakeSum[n - 1][m - 1][0];
    }
};
int main()
{

    return 0;
}