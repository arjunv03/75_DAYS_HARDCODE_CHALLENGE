// https://leetcode.com/problems/longest-substring-of-one-repeating-character/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
struct Node
{
    int maxLen, prefixI, prefixJ, suffixI, suffixJ;
};
class Solution
{
public:
    vector<Node> st;
    string str;
    int n = 0;
    int treeSize = 0;
    void initTree()
    {
        int h = ceil(log2(n));
        int leafSize = 1 << h;
        treeSize = 2 * leafSize;
        str.resize(n, ' ');
        st.resize(treeSize, {0, 0, 0, 0, 0});
        for (int i = 0; i < n; i++)
        {
            st[leafSize + i] = {1, i, i, i, i};
        }
        for (int i = leafSize - 1; i >= 1; i--)
        {
            mergeNode(i);
        }
    }
    void mergeNode(int i)
    {
        Node &left = st[i * 2], &right = st[i * 2 + 1], &parent = st[i];
        if (left.maxLen == 0 && right.maxLen == 0)
        {
            return;
        }
        if (left.maxLen == 0)
        {
            parent = right;
            return;
        }
        if (right.maxLen == 0)
        {
            parent = left;
            return;
        }
        if (str[left.suffixJ] == str[right.prefixI])
        {
            st[i].maxLen = max({left.maxLen, right.maxLen, right.prefixJ - left.suffixI + 1});
            st[i].prefixI = left.prefixI;
            st[i].suffixJ = right.suffixJ;
            st[i].prefixJ = (left.suffixJ - left.prefixI + 1 == left.maxLen) ? right.prefixJ : left.prefixJ;
            st[i].suffixI = (right.suffixJ - right.prefixI + 1 == right.maxLen) ? left.suffixI : right.suffixI;
        }
        else
        {
            st[i] = {max(left.maxLen, right.maxLen), left.prefixI, left.prefixJ, right.suffixI, right.suffixJ};
        }
    }
    void update(int i, char c)
    {
        str[i] = c;
        int leafSize = treeSize / 2;
        int idx = leafSize + i;
        st[idx] = {1, i, i, i, i};
        while (idx > 1)
        {
            idx >>= 1;
            mergeNode(idx);
        }
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> queryIndices)
    {
        n = s.size();
        str = s;
        initTree();
        vector<int> ans;
        for (size_t i = 0; i < queryCharacters.size(); i++)
        {
            update(queryIndices[i], queryCharacters[i]);
            ans.push_back(st[1].maxLen);
        }
        return ans;
    }
};
int main()
{
    
    return 0;
}