// https://leetcode.com/problems/count-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    void helper(vector<ll> &vec, string &s, ll num, vector<ll> &tp)
    {
        string pat = to_string(num);
        if (pat.size() == 1)
        {
            pat = "0" + pat;
        }
        ll n = s.size();
        for (ll i = 0; i < n; i++)
        {
            tp[i + 1] = tp[i] + (s[i] == pat[0]);
        }
        for (ll i = 0; i < n; i++)
        {
            vec[i + 1] = vec[i] + ((s[i] == pat[1]) ? tp[i] : 0);
        }
    }
    int countPalindromes(string s)
    {
        ll n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        vector<vector<ll>> dpLeft(100, vector<ll>(n + 1, 0));
        vector<vector<ll>> dpRight(100, vector<ll>(n + 1, 0));
        vector<ll> tp = dpLeft[0];
        for (ll i = 0; i < 100; i++)
        {
            helper(dpLeft[i], s, i, tp);
            helper(dpRight[i], rev, i, tp);
        }
        ll ans = 0;
        for (ll i = 1; i < n; i++)
        {
            for (ll j = 0; j < 100; j++)
            {
                ans = (ans + dpLeft[j][i - 1] * (dpRight[j][n - i]))%M;
            }
        }
        return ans;
    }
};
int main()
{
    Solution sl;
    cout << sl.countPalindromes("103301");
    return 0;
}