// https://leetcode.com/problems/closest-subsequence-sum/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    void fillSum(vector<ll> &v, vector<ll> &sum)
    {
        ll n = v.size();
        for (ll i = 0; i < (1 << n); i++)
        {
            for (ll j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    sum[i] += v[j];
                }
            }
        }
        sort(sum.begin(), sum.end());
    }
    int minAbsDifference(vector<int> nums, int goal)
    {
        ll n = nums.size();
        vector<ll> leftElements(nums.begin(), nums.begin() + n / 2), rightElements(nums.begin() + n / 2, nums.begin() + n);
        vector<ll> leftSum(1<<leftElements.size()), rightSum(1<<rightElements.size());
        fillSum(leftElements,leftSum);
        fillSum(rightElements,rightSum);
        ll ans = LONG_LONG_MAX;
        for (ll i = 0; i < leftSum.size(); i++)
        {
            ll t1 = -goal - leftSum[i];
            ll t2 = goal - leftSum[i];
            ll idx1 = lower_bound(rightSum.begin(), rightSum.end(), t1) - rightSum.begin();
            ll idx2 = lower_bound(rightSum.begin(), rightSum.end(), t2) - rightSum.begin();
            for (ll j = -1; j <= 1; j++)
            {
                if (0 <= idx1 + j && idx1 + j < rightSum.size())
                {
                    ans = min(ans, abs(goal - leftSum[i] - rightSum[idx1 + j]));
                }
                if (0 <= idx2 + j && idx2 + j < rightSum.size())
                {
                    ans = min(ans, abs(goal - leftSum[i] - rightSum[idx2 + j]));
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