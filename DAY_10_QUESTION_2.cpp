// https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    vector<ll> dp;
    ll m, k, ans;
    void helper(ll nL, ll nR, ll flag)
    {
        ll toRem = nL * (nL + 1) / 2 + nR * (nR + 1) / 2;
        for (ll i = nL; i < m - nR; i++)
        {
            ll currMoves = (dp[i + nR + 1] - dp[i + ((flag == 1 || flag == 2) ? 1 : 0)]) - (dp[i + ((flag == 1) ? 1 : 0)] - dp[i - nL]);
            ans = min(ans, currMoves - toRem);
        }
    }
    int minMoves(vector<int> nums, int k)
    {
        vector<ll> pos1;
        for (ll i = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                pos1.push_back(i);
            }
        }
        m = pos1.size();
        dp.resize(m + 1, 0);
        for (ll i = 0; i < m; i++)
        {
            dp[i + 1] = pos1[i] + dp[i];
        }
        ans = INT_MAX;
        this->k = k;
        if (k % 2)
        {
            helper(k / 2, (k - 1) / 2, 2);
        }
        else
        {
            helper(k / 2, (k - 1) / 2, 0);
            helper((k - 1) / 2, k / 2, 1);
        }
        return ans;
    }
};
ll main()
{
    return 0;
}