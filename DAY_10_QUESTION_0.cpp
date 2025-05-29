// https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minSwap(vector<int> nums1, vector<int> nums2)
    {
        int n = nums1.size();
        vector<pair<int, int>> dp(n, {1e7, 1e7});
        dp[0].first = 0;
        dp[0].second = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i])
            {
                dp[i].first = dp[i - 1].first;
            }
            if (nums2[i - 1] < nums1[i] && nums1[i - 1] < nums2[i])
            {
                dp[i].first = min(dp[i].first, dp[i - 1].second);
            }
            if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i])
            {
                dp[i].second = dp[i - 1].first + 1;
            }
            if (nums2[i - 1] < nums2[i] && nums1[i - 1] < nums1[i])
            {
                dp[i].second = min(dp[i].second, dp[i - 1].second + 1);
            }
        }
        return min(dp[n - 1].first, dp[n - 1].second);
    }
};
int main()
{
    return 0;
}