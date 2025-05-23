// https://leetcode.com/problems/shortest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int kmp(const string &sRev, const string &s)
    {
        string newString = s + '#' + sRev;
        int size = newString.length();
        vector<int> pi(size, 0);
        int i = 1, k = 0;
        while (i < size)
        {
            if (newString[i] == newString[k])
            {
                k++;
                pi[i] = k;
                i++;
            }
            else
            {
                if (k > 0)
                {
                    k = pi[k - 1];
                }
                else
                {
                    pi[i] = 0;
                    i++;
                }
            }
        }
        return pi[size - 1];
    }
    string shortestPalindrome(string s)
    {
        string sRev = string(s.rbegin(), s.rend());
        return string(sRev).substr(0, s.length() - kmp(sRev, s)) + s;
    }
};

int main()
{

    return 0;
}