// https://leetcode.com/problems/get-the-maximum-score/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int ans = target[0];
        for (int i = 1; i < target.size(); i++)
        {
            ans += max(0, target[i] - target[i - 1]);
        }
        return ans;
    }
};
int main()
{

    return 0;
}
