// https://leetcode.com/problems/reverse-pairs/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    int ans;
    void merge(int lo, int hi, vector<int> &nums)
    {
        int mid = (lo + hi) / 2;
        for (int i = lo; i <= mid; i++)
        {
            int j = mid + 1;
            while (j <= hi && ((ll)nums[i] > (2l * (ll)nums[j])))
            {
                j++;
            }
            ans += (j - mid - 1);
        }
        sort(nums.begin() + lo, nums.begin() + hi + 1);
    }
    void mergeSort(int lo, int hi, vector<int> &nums)
    {
        if (lo >= hi)
        {
            return;
        }
        int mid = (lo + hi) / 2;
        mergeSort(lo, mid, nums);
        mergeSort(mid + 1, hi, nums);
        merge(lo, hi, nums);
    }
    int reversePairs(vector<int> &nums)
    {
        ans = 0;
        int n = nums.size();
        mergeSort(0, n - 1, nums);
        return ans;
    }
};

int main()
{

    return 0;
}