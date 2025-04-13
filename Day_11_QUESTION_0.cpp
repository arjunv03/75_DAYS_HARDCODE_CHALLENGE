// https://leetcode.com/problems/building-boxes/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minimumBoxes(int n)
    {
        ll curr = 0;
        ll i = 1;
        while (curr < n)
        {
            ll next = (i * (i + 1)) / 2;
            if (curr + next <= n)
            {
                curr += next;
                i++;
            }
            else
            {
                break;
            }
        }
        if (curr == n)
        {
            return (i * (i - 1)) / 2;
        }
        ll j = 0;
        while (curr < n)
        {
            curr += (++j);
        }
        return (i * (i - 1)) / 2 + j;
    }
};
int main()
{
    
    return 0;
}