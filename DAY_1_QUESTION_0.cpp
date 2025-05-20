// https://leetcode.com/problems/find-substring-with-given-hash-value/description/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        int n = s.size();
        long long currHashValue = 0;
        long long deletePower = 1;
        long long ans = n;
        for (int i = n - 1; i >= 0; i--)
        {
            currHashValue = ((currHashValue * power) + (s[i] - 'a' + 1)) % modulo;
            if (i + k >= n)
            {
                deletePower = (deletePower * power) % modulo;
            }
            else
            {
                currHashValue = (currHashValue - (deletePower * (s[i + k] - 'a' + 1)) % modulo + modulo) % modulo;
            }
            if (currHashValue == hashValue)
            {
                ans = i;
            }
        }
        return s.substr(ans, k);
    }
};
int main()
{
    return 0;
}