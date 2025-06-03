// https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    vector<int> dp;
    vector<int> nums1, nums2;
    int helper(int i, int mask)
    {
        if (i >= nums1.size())
        {
            return 0;
        }
        if (dp[mask] == INT_MAX)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                if (!(mask & (1 << j)))
                {
                    dp[mask] = min(dp[mask], (nums1[i] ^ nums2[j]) + helper(i + 1, mask | (1 << j)));
                }
            }
        }
        return dp[mask];
    }
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        int n = nums1.size();
        int size = 1 << n;
        dp.assign(size, INT_MAX);
        return helper(0, 0);
    }
};
int main()
{

    return 0;
}
