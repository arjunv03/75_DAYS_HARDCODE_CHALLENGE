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
        return n - dp[0][n - 1];
    }
};
int main()
{

    return 0;
}