// https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        int col = min((int)mat[0].size(), k);
        priority_queue<int> pq;
        pq.push(0);
        for (const auto &row : mat)
        {
            priority_queue<int> nextPq;
            while (!pq.empty())
            {
                int currSum = pq.top();
                pq.pop();
                for (int c = 0; c < col; ++c)
                {
                    int newSum = currSum + row[c];
                    nextPq.push(newSum);
                    if (nextPq.size() > k)
                    {
                        nextPq.pop();
                    }
                }
            }
            pq = move(nextPq);
        }
        return pq.top();
    }
};
int main()
{

    return 0;
}
