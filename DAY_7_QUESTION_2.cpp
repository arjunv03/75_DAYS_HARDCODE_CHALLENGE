//  https://leetcode.com/problems/remove-boxes/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    vector<int> ipBox;
    vector<vector<vector<ll>>> dp;
    ll solve(ll i, ll j, ll k)
    {
        if (i > j)
        {
            return 0;
        }
        if (dp[i][j][k] != -1)
        {
            return dp[i][j][k];
        }
        ll kOg = k;
        ll iOg = i;
        while (i + 1 <= j && ipBox[i] == ipBox[i + 1])
        {
            k++;
            i++;
        }
        ll ans = (k + 1) * (k + 1) + solve(i + 1, j, 0);
        for (ll m = i + 1; m <= j; m++)
        {
            if (ipBox[i] == ipBox[m])
            {
                ans = max(ans,solve(m, j, k + 1) + solve(i + 1, m - 1, 0));
            }
        }

        return dp[iOg][j][kOg] = ans;
    }

    int removeBoxes(vector<int> &inputBoxes)
    {
        ipBox = inputBoxes;
        ll n = ipBox.size();
        dp = vector<vector<vector<ll>>>(n, vector<vector<ll>>(n, vector<ll>(n, -1)));
        return solve(0, n - 1, 0);
    }
};

int main()
{
    return 0;
}