// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2)
    {
        int xor1 = 0;
        for (auto &&i : arr1)
        {
            xor1 ^= i;
        }
        int xor2 = 0;
        for (auto &&i : arr2)
        {
            xor2 ^= i;
        }
        return xor1 & xor2;
    }
};
int main()
{
    return 0;
}
