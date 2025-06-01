// https://leetcode.com/problems/frog-jump/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        map<int, set<int>> positonToNextJumpLen;
        positonToNextJumpLen[0] = {1};
        while (!positonToNextJumpLen.empty())
        {
            auto tp = positonToNextJumpLen.begin();
            for (auto &&currJumpLen : tp->second)
            {
                if (tp->first + currJumpLen == stones[n - 1])
                {
                    return true;
                }
                auto isStoneOnNexPos = binary_search(stones.begin(), stones.end(), tp->first + currJumpLen);
                if (isStoneOnNexPos)
                {
                    if (currJumpLen > 1)
                    {
                        positonToNextJumpLen[tp->first + currJumpLen].insert(currJumpLen - 1);
                    }
                    positonToNextJumpLen[tp->first + currJumpLen].insert(currJumpLen);
                    positonToNextJumpLen[tp->first + currJumpLen].insert(currJumpLen + 1);
                }
            }
            positonToNextJumpLen.erase(tp->first);
        }
        return false;
    }
};
int main()
{

    return 0;
}
