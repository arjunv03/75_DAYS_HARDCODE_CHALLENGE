// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        vector<vector<vector<int>>> dp(3, vector<vector<int>>(n + 1, {-1, -1, -1, -1}));
        for (int i = 0; i < 3; i++)
        {
            for (int j = (1 + i) * k; j <= n; j++)
            {
                int maxSumLeft = preSum[j] - preSum[j - k] + (i > 0 ? dp[i - 1][j - k][0] : 0);
                if (dp[i][j - 1][0] < maxSumLeft)
                {
                    if (i == 0)
                    {
                        dp[i][j] = {maxSumLeft, j - k, -1, -1};
                    }
                    else if (i == 1)
                    {
                        dp[i][j] = {maxSumLeft, dp[i - 1][j - k][1], j - k, -1};
                    }
                    else
                    {
                        dp[i][j] = {maxSumLeft, dp[i - 1][j - k][1], dp[i - 1][j - k][2], j - k};
                    }
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return {dp[2][n][1], dp[2][n][2], dp[2][n][3]};
    }
};
int main()
{

    return 0;
}