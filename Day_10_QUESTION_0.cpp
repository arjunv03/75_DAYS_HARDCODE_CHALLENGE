// https://leetcode.com/problems/maximal-rectangle/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    vector<int> ht;
    void fillMaxW(vector<int> &left)
    {
        stack<int> st;
        for (int i = 0; i < left.size(); i++)
        {
            while (!st.empty() && ht[st.top()] >= ht[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                left[i] = i;
            }
            else
            {
                left[i] = i - st.top() - 1;
            }
            st.push(i);
        }
    }
    int helper()
    {
        vector<int> leftW(ht.size(), 0), rightW(ht.size(), 0);
        fillMaxW(leftW);
        reverse(ht.begin(), ht.end());
        fillMaxW(rightW);
        reverse(ht.begin(), ht.end());
        reverse(rightW.begin(), rightW.end());
        int ans = 0;
        for (int i = 0; i < ht.size(); i++)
        {
            ans = max(ans, ht[i] * (leftW[i] + rightW[i] + 1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        ht.resize(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ht[j] = (('1' == matrix[i][j]) ? (ht[j] + 1) : 0);
            }
            ans = max(ans, helper());
        }
        return ans;
    }
};
int main()
{
    return 0;
}