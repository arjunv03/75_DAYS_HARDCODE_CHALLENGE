// https://leetcode.com/problems/split-array-with-same-average/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    void fill(vector<set<ll>> &sum, vector<ll> &nums)
    {
        ll n = nums.size();
        for (ll i = 0; i < (1 << n); i++)
        {
            ll thisSum = 0;
            ll ct = 0;
            for (ll j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    thisSum += nums[j];
                    ct++;
                }
            }
            sum[ct].insert(thisSum);
        }
    }
    bool splitArraySameAverage(vector<int> nums)
    {
        ll n = nums.size();
        vector<ll> left, right;
        for (ll i = 0; i < (n / 2); i++)
        {
            left.push_back(nums[i]);
        }
        for (ll i = n / 2; i < n; i++)
        {
            right.push_back(nums[i]);
        }
        vector<set<ll>> sumSubsetLeft(left.size() + 1);
        vector<set<ll>> sumSubsetRight(right.size() + 1);
        fill(sumSubsetLeft, left);
        fill(sumSubsetRight, right);
        ll totalSum = accumulate(nums.begin(), nums.end(), 0);
        for (ll i = 0; i <= left.size(); i++)
        {
            for (ll j = 0; j <= right.size(); j++)
            {
                ll n1 = i + j;
                if (n1 == 0 || n1 == n)
                {
                    continue;
                }
                for (auto &&a : sumSubsetLeft[i])
                {
                    ll b = ((totalSum * n1) / n) - a;
                    if (sumSubsetRight[j].find(b) != sumSubsetRight[j].end())
                    {
                        ll leftProduct = (a + b) * (n - n1);
                        ll rightProduct = (totalSum - a - b) * (n1);
                        if (leftProduct == rightProduct)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
int main()
{

    return 0;
}