// https://leetcode.com/problems/recover-the-original-array/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    vector<int> helper(vector<int> &v1, int k)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < v1.size(); i++)
        {
            if (mp.find(v1[i]) != mp.end() && mp[v1[i]] > 0)
            {
                ans.push_back(v1[i] - k);
                mp[v1[i]]--;
                if (mp[v1[i]] == 0)
                {
                    mp.erase(v1[i]);
                }
            }
            else
            {
                mp[v1[i] + 2 * k]++;
            }
        }
        if (((ans.size() * 2) == v1.size()) && mp.size() == 0)
        {
            return ans;
        }
        return {};
    }
    vector<int> recoverArray(vector<int> nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            if ((nums[i] - nums[0]) % 2 == 0 && nums[0] != nums[i])
            {
                int k = (nums[i] - nums[0]) / 2;
                vector<int> ans = helper(nums, k);
                if (!ans.empty())
                {
                    return ans;
                }
            }
        }
        return {};
    }
};
int main()
{

    return 0;
}