// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int maxSum(vector<int> nums1, vector<int> nums2)
    {
        map<int, pair<int, int>> mpFre;
        int n = nums1.size(), m = nums2.size();
        vector<ll> presum1(nums1.size() + 1, 0l), presum2(nums2.size() + 1, 0l);
        for (int i = 0; i < nums1.size(); i++)
        {
            mpFre[nums1[i]] = {i + 1, -1};
            presum1[i + 1] = nums1[i] + presum1[i];
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (mpFre.find(nums2[i]) != mpFre.end())
            {
                mpFre[nums2[i]].second = i + 1;
            }
            presum2[i + 1] = nums2[i] + presum2[i];
        }
        int lastEqualIdxNums1 = 0, lastEqualIdxNums2 = 0;
        ll ans = 0;
        for (auto &&i : mpFre)
        {
            if (i.second.second != -1)
            {
                ans = (ans + max(presum1[i.second.first] - presum1[lastEqualIdxNums1], presum2[i.second.second] - presum2[lastEqualIdxNums2])) % M;
                lastEqualIdxNums1 = i.second.first, lastEqualIdxNums2 = i.second.second;
            }
        }
        ans = (ans + max(presum1[n] - presum1[lastEqualIdxNums1], presum2[m] - presum2[lastEqualIdxNums2])) % M;
        return ans;
    }
};
int main()
{
    Solution sl;
    cout << sl.maxSum({2, 4, 5, 8, 10}, {4, 6, 8, 9});
    return 0;
}
