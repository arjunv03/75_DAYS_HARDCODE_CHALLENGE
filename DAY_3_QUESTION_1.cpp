// https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minimumTime(string s)
    {
        int n = s.size(), left = 0, minTime = n;
        for (int i = 0; i < n; i++)
        {
            left = min(left + ((s[i] - '0') * 2), i + 1);
            minTime = min(minTime, left + n - 1 - i);
        }
        return minTime;
    }
};
int main()
{

    return 0;
}