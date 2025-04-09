// https://leetcode.com/problems/the-number-of-good-subsets/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    set<ll> prime = {2, 3, 5, 6, 7, 10, 11, 13, 14, 15, 17, 19, 21, 22, 23, 26, 29, 30};
    int numberOfGoodSubsets(vector<int> nums)
    {
        map<ll, ll> mp;
        cout << prime.size() << endl;
        ll ct1 = 0;
        for (auto &&i : nums)
        {
            if (prime.find(i) != prime.end())
            {
                mp[i]++;
            }
            ct1 += (i == 1);
        }
        vector<pair<ll, ll>> newPrime;
        for (auto &&i : mp)
        {
            newPrime.push_back({i.first, i.second});
        }
        ll ans = 0;
        int pSize = newPrime.size();
        for (int i = 1; i < (1 << pSize); i++)
        {
            bool flag = 1;
            ll product = 1, currans = 0;
            for (int j = 0; j < pSize; j++)
            {
                if ((i & (1 << j)))
                {
                    if (product == 1)
                    {
                        product = newPrime[j].first;
                        currans = newPrime[j].second;
                    }
                    else if (1 == __gcd(newPrime[j].first, product))
                    {
                        product = product * newPrime[j].first;
                        currans = (currans * newPrime[j].second) % M;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                ans = (ans + currans) % M;
            }
        }
        for (int i = 0; i < ct1; i++)
        {
            ans = (ans * 2l) % M;
        }
        return ans;
    }
};
int main()
{

    return 0;
}