// https://leetcode.com/problems/set-intersection-size-at-least-two/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
bool comp(vector<int> &a, vector<int> &b)
{
    return (a[1] != b[1]) ? a[1] < b[1] : a[0] > b[0];
}
class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> intervals)
    {
        sort(intervals.begin(), intervals.end(), comp);
        int m = 0, largest = -1, second = -1;
        for (auto &it : intervals)
        {
            int a = it[0], b = it[1];
            bool isLargeTaken = (a <= largest);
            bool isSecondTaken = (a <= second);
            if (!(isLargeTaken && isSecondTaken))
            {
                m += (isLargeTaken ? 1 : 2);
                second = (isLargeTaken ? largest : b - 1);
                largest = b;
            }
        }
        return m;
    }
};
int main()
{
    
    return 0;
}