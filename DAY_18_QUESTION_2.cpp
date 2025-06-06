// https://leetcode.com/problems/allocate-mailboxes/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minDistance(vector<int> houses, int numMails)
    {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        vector<vector<ll>> cost(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int mid = i + (j - i) / 2;
                for (int x = i; x <= j; x++)
                {
                    cost[i][j] += abs(houses[x] - houses[mid]);
                }
            }
        }
        vector<vector<ll>> dp(numMails, vector<ll>(n + 1, M));
        for (int j = 0; j < n + 1; j++)
        {
            dp[0][j] = (j == 0) ? 0 : cost[0][j - 1];
        }
        for (int i = 1; i < numMails; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = i; k <= j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + cost[k - 1][j - 1]);
                }
            }
        }
        return (int)dp[numMails - 1][n];
    }
};

int main()
{
    return 0;
}