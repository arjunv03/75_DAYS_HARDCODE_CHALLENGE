// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        int legs = 2 * k;
        vector<int> currDp(legs + 1, 0), prevDp(legs + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < legs; j++)
            {
                currDp[j] = max(((j % 2 == 0) ? -1 : 1) * prices[i] + prevDp[j + 1], prevDp[j]);
            }
            prevDp = currDp;
        }
        return prevDp[0];
    }
};
int main()
{

    return 0;
}