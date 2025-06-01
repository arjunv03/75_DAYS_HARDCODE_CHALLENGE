// https://leetcode.com/problems/set-intersection-size-at-least-two/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
bool comp(vector<int> &a, vector<int> &b)
{
    return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
}
class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), comp);
        int n = intervals.size();
        vector<int> temp(n, 2);
        int ans = 0;
        for (int t = n - 1; t >= 0; t--)
        {
            int m = temp[t];
            for (int p = intervals[t][0]; p < intervals[t][0] + m; p++)
            {
                for (int i = 0; i <= t; i++)
                {
                    temp[i] -= (temp[i] > 0 && p <= intervals[i][1]) ? 1 : 0;
                }
                ans++;
            }
        }
        return ans;
    }
};
int main()
{
    
    return 0;
}