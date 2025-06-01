// https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int longestPalindrome(string word1, string word2)
    {
        string s = word1 + word2;
        int n = s.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, 0}));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; i < n && j < n; i++, j++)
            {
                if (gap == 0)
                {
                    dp[i][j] = {0, 1};
                }
                else if (gap == 1)
                {
                    dp[i][j].first = (s[i] == s[j]) ? 2 : 0;
                    dp[i][j].second = (s[i] == s[j]) ? 2 : 1;
                }
                else
                {
                    dp[i][j].first = (s[i] == s[j]) ? 2 + dp[i + 1][j - 1].second : 0;
                    dp[i][j].second = max({((s[i] == s[j]) ? 2 : 0) + dp[i + 1][j - 1].second, dp[i + 1][j].second, dp[i][j - 1].second});
                }
            }
        }
        int ans = 0;
        int n1 = word1.size(), n2 = word2.size();
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                ans = max(dp[i][n1 + j].first, ans);
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}
