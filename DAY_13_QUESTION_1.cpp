// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int n, m;
    vector<int> nums;
    vector<int> multipliers;
    int helper(vector<vector<ll>> &dp, int i, int j)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }
        if (dp[i][j] != LONG_LONG_MIN)
        {
            return dp[i][j];
        }
        dp[i][j] = max(helper(dp, i + 1, j + 1) + ((ll)nums[j] * (ll)multipliers[i]),
                       helper(dp, i + 1, j) + ((ll)nums[n - (i - j) - 1] * (ll)multipliers[i]));
        return dp[i][j];
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        n = nums.size(), m = multipliers.size();
        this->nums = nums;
        this->multipliers = multipliers;
        vector<vector<ll>> dp(m, vector<ll>(n, LONG_LONG_MIN));
        return helper(dp, 0, 0);
    }
};
int main()
{

    return 0;
}
