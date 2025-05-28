// https://leetcode.com/problems/count-different-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int countPalindromicSubsequences(string s)
    {
        int n = s.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(4, 0)));
        for (int i = 0; i < n; ++i)
        {
            dp[i][i][s[i] - 'a'] = 1;
        }
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i + l <= n; i++)
            {
                int j = i + l - 1;
                for (char c = 'a'; c <= 'd'; c++)
                {
                    int k = c - 'a';
                    if (s[i] == c && s[j] == c)
                    {
                        dp[i][j][k] = 2 + accumulate(dp[i + 1][j - 1].begin(), dp[i + 1][j - 1].end(), 0ll) % M;
                    }
                    else if (s[i] == c)
                    {
                        dp[i][j][k] = dp[i][j - 1][k];
                    }
                    else if (s[j] == c)
                    {
                        dp[i][j][k] = dp[i + 1][j][k];
                    }
                    else
                    {
                        dp[i][j][k] = dp[i + 1][j - 1][k];
                    }
                }
            }
        }
        ll ans = 0;
        for (int k = 0; k < 4; k++)
        {
            ans = (ans + dp[0][n - 1][k]) % M;
        }
        return (int)(ans);
    }
};
int main()
{

    return 0;
}
