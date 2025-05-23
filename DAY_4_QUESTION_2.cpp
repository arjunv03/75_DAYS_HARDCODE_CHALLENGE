// https://leetcode.com/problems/count-of-range-sum/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    ll lowerSum, upperSum;
    ll ans = 0;
    void merge(vector<ll> &preSum, ll low, ll mid, ll high)
    {
        ll j = mid + 1, k = mid + 1;
        for (ll i = low; i <= mid; i++)
        {
            while (j <= high && preSum[j] - preSum[i] <= upperSum)
            {
                j++;
            }
            while (k <= high && preSum[k] - preSum[i] < lowerSum)
            {
                k++;
            }
            ans += (j - k);
        }
        sort(preSum.begin() + low, preSum.begin() + high + 1);
    }

    void mergeSort(vector<ll> &preSum, ll low, ll high)
    {
        if (low >= high)
        {
            return;
        }
        ll mid = low + (high - low) / 2;
        mergeSort(preSum, low, mid);
        mergeSort(preSum, mid + 1, high);
        merge(preSum, low, mid, high);
    }

    int countRangeSum(vector<int> nums, int lower, int upper)
    {
        ll n = nums.size();
        lowerSum = lower;
        upperSum = upper;
        ans = 0;
        vector<ll> preSum(n + 1, 0);
        for (ll i = 0; i < n; i++)
        {
            preSum[i + 1] = preSum[i] + nums[i];
        }
        mergeSort(preSum, 0, n);
        return ans;
    }
};
int main()
{
    Solution sl;
    sl.countRangeSum({-2, 5, -1}, -2, 2);
    return 0;
}