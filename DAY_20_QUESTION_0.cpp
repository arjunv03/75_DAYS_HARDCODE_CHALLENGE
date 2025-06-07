// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    unordered_map<int, int> mpDp;
    int helper(int n)
    {
        if (n <= 1)
        {
            return 1;
        }
        if (mpDp.find(n) != mpDp.end())
        {
            return mpDp[n];
        }
        return 1 + min(n % 2 + helper(n / 2), n % 3 + helper(n / 3));
    }
    int minDays(int n)
    {
        mpDp.clear();
        return helper(n);
    }
};
int main()
{

    return 0;
}