// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minCost(int n, vector<int> cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int size = cuts.size();
        vector<vector<int>> dpCost(size, vector<int>(size, M));
        for (int gap = 0; gap < size; gap++)
        {
            for (int i = 0, j = gap; i < size && j < size; i++, j++)
            {
                if (gap <= 1)
                {
                    dpCost[i][j] = 0;
                }
                else
                {
                    for (int k = i + 1; k <= j - 1; k++)
                    {
                        dpCost[i][j] = min(dpCost[i][j], cuts[j] - cuts[i] + dpCost[i][k] + dpCost[k][j]);
                    }
                }
            }
        }
        return dpCost[0][size - 1];
    }
};
int main()
{

    return 0;
}
