// https://leetcode.com/problems/sum-of-floored-pairs/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int sumOfFlooredPairs(vector<int> &nums)
    {
        int maxSize = 1e5;
        vector<int> counts(maxSize + 1, 0);
        for (auto &&num : nums)
        {
            counts[num]++;
        }
        for (int i = 1; i <= maxSize; i++)
        {
            counts[i] += counts[i - 1];
        }
        ll total = 0;
        for (int i = 1; i <= maxSize; i++)
        {
            if (counts[i] > counts[i - 1])
            {
                ll sum = 0;
                for (int j = 1; i * j <= maxSize; j++)
                {
                    ll lower = i * j - 1;
                    ll upper = min(i * (j + 1) - 1, maxSize);
                    ll countInRange = counts[upper] - counts[lower];
                    sum += (ll)countInRange * j;
                }
                ll freq = counts[i] - counts[i - 1];
                total = (total + (sum % M) * freq) % M;
            }
        }
        return (int)total;
    }
};
int main()
{

    return 0;
}
