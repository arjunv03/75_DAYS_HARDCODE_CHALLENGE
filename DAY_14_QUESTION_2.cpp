// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minInsertions(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max({dp[i][j - 1], (s[i - 1] == s[n - j]) + dp[i - 1][j - 1], dp[i - 1][j]});
            }
        }
        return n - dp[n][n];
    }
};

int main()
{
    return 0;
}
