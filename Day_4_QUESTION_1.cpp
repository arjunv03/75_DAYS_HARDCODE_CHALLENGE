// https://leetcode.com/problems/maximum-and-sum-of-array/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    vector<int> dp;
    int numSlots;
    int helper(int idx, int i, vector<int> &nums)
    {
        if (dp[i] > 0)
        {
            return dp[i];
        }
        if (idx < 0)
        {
            return 0;
        }
        for (int slot = 1, bit = 1; slot <= numSlots; ++slot, bit *= 3)
        {
            if ((i / bit) % 3 > 0)
            {
                dp[i] = max(dp[i], (nums[idx] & slot) + helper(idx - 1, i - bit, nums));
            }
        }
        return dp[i];
    }
    int maximumANDSum(vector<int> &nums, int numSlots)
    {
        int i = pow(3, numSlots) - 1;
        this->numSlots = numSlots;
        dp.resize(i + 1, 0);
        return helper(nums.size() - 1, i, nums);
    }
};
int main()
{

    return 0;
}