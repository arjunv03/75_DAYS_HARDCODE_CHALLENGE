// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    vector<vector<ll>> dp;
    vector<int> multipliers;
    vector<int> nums;
    ll helper(int numIdx, int multiIdx)
    {
        if (multiIdx == multipliers.size())
        {
            return 0;
        }
        if (dp[numIdx][multiIdx] != -1)
        {
            return dp[numIdx][multiIdx];
        }
        int rightNumIdx = nums.size() - (multiIdx - numIdx) - 1;
        dp[numIdx][multiIdx] = max(helper(numIdx, multiIdx + 1) + multipliers[multiIdx] * nums[rightNumIdx],
                                   helper(numIdx + 1, multiIdx + 1) + multipliers[multiIdx] * nums[numIdx]);
        return dp[numIdx][multiIdx];
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        this->nums = nums;
        this->multipliers = multipliers;
        int n = nums.size();
        int m = multipliers.size();
        dp.resize(m, vector<ll>(m, -1));
        return helper(0, 0);
    }
};
int main()
{
    
    return 0;
}