// https://leetcode.com/problems/palindrome-partitioning-ii/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<int>> isPalindrome(n, vector<int>(n, 0));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; i < n && j < n; i++, j++)
            {
                if (gap == 0)
                {
                    isPalindrome[i][j] = 1;
                }
                else if (gap == 1)
                {
                    isPalindrome[i][j] = (s[i] == s[j]);
                }
                else
                {
                    isPalindrome[i][j] = (isPalindrome[i + 1][j - 1] && s[i] == s[j]);
                }
            }
        }
        vector<int> dp(n, 5000);
        for (int i = 0; i < n; i++)
        {
            if (isPalindrome[0][i])
            {
                dp[i] = 0;
            }
            else
            {
                for (int j = 1; j <= i; j++)
                {
                    if (isPalindrome[j][i])
                    {
                        dp[i] = min(dp[i], dp[j - 1] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
int main()
{

    return 0;
}
