// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int numOfWays(int n)
    {
        ll a121 = 6, a123 = 6, b121, b123, mod = 1e9 + 7;
        for (ll i = 1; i < n; ++i)
        {
            b121 = a121 * 3 + a123 * 2;
            b123 = a121 * 2 + a123 * 2;
            a121 = b121 % mod;
            a123 = b123 % mod;
        }
        return (a121 + a123) % mod;
    }
};
int main()
{

    return 0;
}
