// https://leetcode.com/problems/frog-jump/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    bool canCross(vector<int> stones)
    {
        map<int, set<int>> pos;
        for (auto &&i : stones)
        {
            pos[i] = {};
        }
        pos[0] = {0};
        for (auto &&i : pos)
        {
            for (auto &&j : i.second)
            {
                for (int k = -1; k <= 1; k++)
                {
                    if (pos.find(i.first + j + k) != pos.end() && (j + k != 0))
                    {
                        pos[i.first + j + k].insert(j + k);
                    }
                }
            }
        }
        return (pos[stones.back()].size() > 0);
    }
};
int main()
{
    
    return 0;
}