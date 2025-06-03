// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int countOrders(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        ll ans = 6;
        for (ll i = 2; i < n; i++)
        {
            ll last = ans;
            ans = ((i + 1) * (2 * i + 1) * last) % M;
        }
        return ans;
    }
};
int main()
{

    return 0;
}
