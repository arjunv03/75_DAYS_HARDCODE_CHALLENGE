// https://leetcode.com/problems/russian-doll-envelopes/description/

#include <bits/stdc++.h>
using namespace std;
bool comp(vector<int> &env1, vector<int> &env2)
{
    if (env1[0] == env2[0])
    {
        return env1[1] > env2[1];
    }
    return env1[0] < env2[0];
}
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> lis = {envelopes[0][1]};
        for (int i = 1; i < envelopes.size(); i++)
        {
            if (lis.back() < envelopes[i][1])
            {
                lis.push_back(envelopes[i][1]);
            }
            else
            {
                auto itr = lower_bound(lis.begin(), lis.end(), envelopes[i][1]);
                if (itr != lis.end())
                {
                    *itr = envelopes[i][1];
                }
            }
        }
        return lis.size();
    }
};
int main()
{
    return 0;
}