// https://leetcode.com/problems/count-array-pairs-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    ll countPairs(vector<int> &nums, int k)
    {
        unordered_map<ll, ll> gcds;
        ll ans = 0;
        for (auto &&i : nums)
        {
            ll newGcd = __gcd(k, i);
            for (auto &&j : gcds)
            {
                if ((j.first * newGcd) % k == 0)
                {
                    ans += j.second;
                }
            }
            gcds[newGcd]++;
        }
        return ans;
    }
};
int main()
{
    
    return 0;
}