// https://leetcode.com/problems/number-of-different-subsequences-gcds/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        vector<int> gcdCount(2e5 + 1, 0);
        for (auto &&i : nums)
        {
            for (int j = 1; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    gcdCount[j] = __gcd(gcdCount[j], i);
                    gcdCount[i / j] = __gcd(gcdCount[i / j], i);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < gcdCount.size(); i++)
        {
            if (i == gcdCount[i])
            {
                ans++;
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}

// 20

// 2 4