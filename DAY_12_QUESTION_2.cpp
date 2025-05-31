// https://leetcode.com/problems/palindrome-partitioning-iv/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    bool checkPartitioning(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; i < n && j < n; i++, j++)
            {
                if (gap <= 1)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = (s[i] == s[j]) ? dp[i + 1][j - 1] : 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (dp[0][i - 1] && dp[i][j - 1] && dp[j][n - 1])
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};
int main()
{
    
    return 0;
}