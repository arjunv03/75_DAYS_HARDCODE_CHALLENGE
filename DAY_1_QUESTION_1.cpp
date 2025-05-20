// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> left(n, 0), right(n, 0);
        int lowestFromLeft = prices[0];
        int greatestFromRight = prices[n - 1];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], prices[i] - lowestFromLeft);
            right[n - i - 1] = max(right[n - i], greatestFromRight - prices[n - i - 1]);
            lowestFromLeft  = min(lowestFromLeft,prices[i]);
            greatestFromRight  = max(greatestFromRight,prices[n - i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, left[i] + right[i]);
        }
        return ans;
    }
};
int main()
{
    return 0;
}