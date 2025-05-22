// https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int numberOfWays(string corridor)
    {
        vector<ll> seatPos;
        for (size_t i = 0; i < corridor.size(); i++)
        {
            if (corridor[i] == 'S')
            {
                seatPos.push_back(i);
            }
        }
        if (((seatPos.size() % 2) == 1) || (seatPos.size() == 0))
        {
            return 0;
        }
        ll n = seatPos.size();
        ll ans = 1;
        for (int i = 1; i < n - 1; i += 2)
        {
            ans = ans * (seatPos[i + 1] - seatPos[i]);
            ans = ans % M;
        }
        return ans;
    }
};
int main()
{

    return 0;
}