// https://leetcode.com/problems/count-number-of-special-subsequences/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int countSpecialSubsequences(vector<int> nums)
    {
        ll n = nums.size();
        vector<ll> power2(n + 1, 1);
        for (int i = 0; i < n; i++)
        {
            power2[i + 1] = (power2[i] * 2) % M;
        }
        vector<ll> dp1(n + 1, 0);
        vector<pair<ll, ll>> dp2(n + 1, {0, 0});
        vector<pair<ll, ll>> dp3(n + 1, {0, 0});
        for (ll i = 0; i < n; i++)
        {
            dp1[i + 1] = dp1[i] + (nums[i] == 0);
        }
        for (ll i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                dp2[i + 1].first = (2 * dp2[i].first) % M;
                dp2[i + 1].second = (((2 * dp2[i].second) + ((ll)power2[dp1[i]]) - 1)) % M;
            }
            else
            {
                dp2[i + 1].first = dp2[i].first;
                dp2[i + 1].second = dp2[i].second;
            }
        }
        for (ll i = 0; i < n; i++)
        {
            if (nums[i] == 2)
            {
                dp3[i + 1].first = (2 * dp3[i].first) % M;
                dp3[i + 1].second = (2 * dp3[i].second + dp2[i].second) % M;
            }
            else
            {
                dp3[i + 1].first = dp3[i].first;
                dp3[i + 1].second = dp3[i].second;
            }
        }
        return dp3[n].second;
    }
};
int main()
{
    Solution sl;
    sl.countSpecialSubsequences({0, 1, 2, 2});

    return 0;
}