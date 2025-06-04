// https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int maximumScore(vector<int> nums, int k)
    {
        map<int, int> prefix, suffix, mpLeft, mpRight;
        for (int i = 0; i <= k; i++)
        {
            mpLeft[nums[i]]++;
        }
        for (int i = 0; i <= k; i++)
        {
            auto itr = mpLeft.begin();
            if (prefix.find(itr->first) == prefix.end())
            {
                prefix[itr->first] = i;
            }
            mpLeft[nums[i]]--;
            if (mpLeft[nums[i]] == 0)
            {
                mpLeft.erase(nums[i]);
            }
        }
        for (int i = k; i < nums.size(); i++)
        {
            mpRight[nums[i]]++;
            auto itr = mpRight.begin();
            suffix[itr->first] = max(suffix[itr->first], i);
        }
        for (auto &&i : prefix)
        {
            cout << i.first << " " << i.second << endl;
        }
        cout << endl;

        for (auto &&i : suffix)
        {
            cout << i.first << " " << i.second << endl;
        }
        int ans = 0;
        for (int i = 0; i <= nums[k]; i++)
        {
            auto leftItr = prefix.lower_bound(i);
            auto rightItr = suffix.lower_bound(i);
            int leftIdx = (leftItr == prefix.end()) ? 0 : leftItr->second;
            int rightIdx = (rightItr == prefix.end()) ? 0 : rightItr->second;
            ans = max(ans, (rightIdx - leftIdx + 1) * i);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
