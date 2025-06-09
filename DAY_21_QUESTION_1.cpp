// https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/
// https://en.wikipedia.org/wiki/Gray_code#Converting_to_and_from_Gray_code

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minimumOneBitOperations(int n)
    {
        int mask = n;
        while (mask)
        { 
            mask >>= 1;
            n ^= mask;
        }
        return n;
    }
};
int main()
{
    return 0;
}