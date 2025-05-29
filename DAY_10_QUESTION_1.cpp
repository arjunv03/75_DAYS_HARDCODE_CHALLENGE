// https://leetcode.com/problems/make-array-strictly-increasing/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        int n1 = arr1.size(), n2 = arr2.size();
        map<int, int> dp;
        dp[0] = arr1[0];
        if (arr2[0] < arr1[0])
        {
            dp[1] = arr2[0];
        }
        for (int i = 1; i < n1; ++i)
        {
            map<int, int> new_dp;
            int x = arr1[i];
            for (auto &it : dp)
            {
                if (it.second < x)
                {
                    if (new_dp.find(it.first) == new_dp.end())
                    {
                        new_dp[it.first] = x;
                    }
                    else
                    {
                        new_dp[it.first] = min(new_dp[it.first], x);
                    }
                }
            }
            for (auto &it : dp)
            {
                auto itr = upper_bound(arr2.begin(), arr2.end(), it.second);
                if (itr != arr2.end())
                {
                    int next = *itr;
                    if (new_dp.find(it.first + 1) == new_dp.end())
                    {
                        new_dp[it.first + 1] = next;
                    }
                    else
                    {
                        new_dp[it.first + 1] = min(new_dp[it.first + 1], next);
                    }
                }
            }
            dp = new_dp;
        }
        if (!dp.empty())
        {
            return dp.begin()->first;
        }
        return -1;
    }
};

int main()
{
    return 0;
}