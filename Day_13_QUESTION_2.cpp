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
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = max({dp[i + 1][j - 1],
                                    dp[i + 1][j],
                                    dp[i][j - 1],
                                    s[i] == s[j] ? dp[i + 1][j - 1] + 2 : 1});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < word1.size(); i++)
        {
            for (int j = 0; j < word2.size(); j++)
            {
                if (word1[i] == word2[j])
                {
                    ans = max(ans, 2 + dp[i + 1][j + word1.size() - 1]);
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}