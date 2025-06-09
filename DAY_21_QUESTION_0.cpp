// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
bool comp(vector<int> &a, vector<int> &b)
{
    return (a[0] - a[1]) < (b[0] - b[1]);
}
class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), comp);
        int ans = 0, cur = 0;
        for (const auto &task : tasks)
        {
            int cost = task[0];
            int mmin = task[1];
            if (mmin > cur)
            {
                ans += (mmin - cur);
                cur = mmin;
            }
            cur -= cost;
        }
        return ans;
    }
};
int main()
{
    return 0;
}