// https://leetcode.com/problems/count-ways-to-make-array-with-product/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
ll cnp[10020][14] = {0};
ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
class Solution
{
public:
    ll helper(vector<int> &q)
    {
        ll ans = 1;
        map<ll, ll> mp;
        for (auto &&i : primes)
        {
            while (q[1] % i == 0)
            {
                mp[i]++;
                q[1] /= i;
            }
        }
        if (q[1] > 1)
        {
            mp[q[1]]++;
        }
        for (auto &&i : mp)
        {
            ans = (ans * cnp[q[0] + i.second - 1][i.second]) % M;
        }
        return ans;
    }
    vector<int> waysToFillArray(vector<vector<int>> queries)
    {
        vector<int> res;
        for (ll i = 0; i < 10020; i++)
        {
            cnp[i][0] = 1;
        }
        for (ll i = 1; i < 10020; i++)
        {
            for (ll j = 1; j < 14; j++)
            {
                cnp[i][j] = (cnp[i - 1][j - 1] + cnp[i - 1][j]) % M;
            }
        }
        for (auto &q : queries)
        {
            res.push_back(helper(q));
        }
        return res;
    }
};
int main()
{
    return 0;
}