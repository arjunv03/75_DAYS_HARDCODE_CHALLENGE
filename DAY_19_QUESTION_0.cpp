// https://leetcode.com/problems/stone-game-iv/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> canWin(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                if (canWin[i - (j * j)] == 0)
                {
                    canWin[i] = 1;
                }
            }
        }
        return canWin[n];
    }
};

int main()
{
    Solution sl;
    sl.winnerSquareGame(10);
    return 0;
}
