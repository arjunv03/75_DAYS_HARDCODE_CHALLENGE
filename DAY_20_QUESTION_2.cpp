// https://leetcode.com/problems/minimize-deviation-in-array/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> pq;
        int minVal = INT_MAX;
        for (int num : nums)
        {
            if (num % 2)
            {
                num = num * 2;
            }
            pq.push(num);
            minVal = min(minVal, num);
        }
        int minDeviation = INT_MAX;
        while (true)
        {
            int maxVal = pq.top();
            pq.pop();
            minDeviation = min(minDeviation, maxVal - minVal);
            if (maxVal % 2)
            {
                break;
            }
            minVal = min(minVal, maxVal/2);
            pq.push(maxVal/2);
        }
        return minDeviation;
    }
};
int main()
{

    return 0;
}