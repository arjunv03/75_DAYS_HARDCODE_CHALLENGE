// https://leetcode.com/problems/number-of-visible-people-in-a-queue/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> heights)
    {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int ct = 0;
            while (!st.empty() && st.top() <= heights[i])
            {
                ct++;
                st.pop();
            }
            ans[i] = ct + (!st.empty());
            st.push(heights[i]);
        }
        return ans;
    }
};
int main()
{
    Solution sl;
    sl.canSeePersonsCount({10, 6, 8, 5, 11, 9});
    return 0;
}