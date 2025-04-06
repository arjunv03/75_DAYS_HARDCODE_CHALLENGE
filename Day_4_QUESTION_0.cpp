// https://leetcode.com/problems/burst-balloons/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int maxCoins(vector<int> nums)
    {
        int n = nums.size();
        ll dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; i < n && j < n; i++, j++)
            {
                ll left = (i - 1 >= 0) ? nums[i - 1] : 1;
                ll right = (j + 1 < n) ? nums[j + 1] : 1;
                for (int k = i; k <= j; k++)
                {
                    int ll = (k - 1 >= 0) ? dp[i][k - 1] : 0;
                    int rr = (k + 1 < n) ? dp[k + 1][j] : 0;
                    dp[i][j] = max(dp[i][j], ll + rr + left * right * nums[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
int main()
{
    return 0;
}