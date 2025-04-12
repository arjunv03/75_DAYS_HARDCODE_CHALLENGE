// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int jobScheduling(vector<int> startTime, vector<int> endTime, vector<int> profit)
    {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++)
        {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        vector<int> maxProfitTillEndTime(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int idx = lower_bound(jobs.begin(), jobs.end(), vector<int>({jobs[i][1], jobs[i][1], 0})) - jobs.begin();
            maxProfitTillEndTime[i + 1] = max(maxProfitTillEndTime[i], maxProfitTillEndTime[idx] + jobs[i][2]);
        }
        return maxProfitTillEndTime[n];
    }
};
int main()
{
    return 0;
}