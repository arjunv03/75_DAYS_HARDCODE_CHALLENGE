// https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    bool isValid(int n, int m)
    {
        vector<int> v(m, 0);
        v[0] = n % 3;
        n = n / 3;
        for (int i = 1; i < m; i++)
        {
            v[i] = n % 3;
            if (v[i] == v[i - 1])
            {
                return 0;
            }
            n = n / 3;
        }
        return 1;
    }
    bool isValidPair(int i, int j, int m)
    {
        vector<int> v1(m, 0), v2(m, 0);
        for (int k = 0; k < m; k++)
        {
            v1[m - k - 1] = i % 3;
            v2[m - k - 1] = j % 3;
            if (v1[m - k - 1] == v2[m - k - 1])
            {
                return 0;
            }
            i /= 3, j /= 3;
        }
        return 1;
    }
    int colorTheGrid(int m, int n)
    {
        map<int, int> mp;
        int idx = 0;
        for (int i = 0; i < pow(3, m); i++)
        {
            if (isValid(i, m))
            {
                mp[i] = idx++;
            }
        }
        map<pair<int, int>, int> mpValid;
        for (auto &&i : mp)
        {
            for (auto &&j : mp)
            {
                if (isValidPair(i.first, j.first, m))
                {
                    mpValid[{i.second, j.second}]++;
                }
            }
        }
        int si = mp.size();
        vector<vector<ll>> dp(si, vector<ll>(n, 0));
        for (int i = 0; i < si; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < si; j++)
            {
                for (int k = 0; k < si; k++)
                {
                    if (mpValid.find({j, k}) != mpValid.end())
                    {
                        dp[j][i] = (dp[j][i] + dp[k][i - 1]) % M;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < si; i++)
        {
            ans = (ans + dp[i][n - 1]) % M;
        }
        return ans;
    }
};
int main()
{
    Solution sl;
    cout << sl.colorTheGrid(5, 15);
    return 0;
}
