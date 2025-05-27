// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    bool isValid(vector<int> &v1, vector<int> &v2)
    {
        return v1[0] <= v2[0] && v1[1] <= v2[1] && v1[2] <= v2[2];
    }
    int maxHeight(vector<vector<int>> &cuboids)
    {
        for (auto &&i : cuboids)
        {
            sort(i.begin(), i.end());
        }
        sort(cuboids.begin(), cuboids.end());
        int n = cuboids.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; j++)
            {
                if (isValid(cuboids[j], cuboids[i]))
                {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
int main()
{

    return 0;
}