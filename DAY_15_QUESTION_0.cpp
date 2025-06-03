// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> mpJumps(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
        {
            mpJumps[max(0, i - ranges[i])] = max(mpJumps[max(0, i - ranges[i])], i + ranges[i] - max(0, i - ranges[i]));
        }
        int ctmpJumps = 1, potantial = 0, curr = mpJumps[0];
        for (int i = 1; i < n; i++)
        {
            potantial = max(potantial - 1, mpJumps[i]);
            curr--;
            if (curr == 0)
            {
                curr = potantial;
                ctmpJumps++;
                potantial = 0;
            }
            if (curr <= 0)
            {
                return -1;
            }
        }
        return ctmpJumps;
    }
};

int main()
{

    return 0;
}
