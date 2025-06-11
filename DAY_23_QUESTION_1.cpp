// https://leetcode.com/problems/word-search-ii/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
struct Node
{
    int isEnd;
    string s;
    vector<Node *> vec;
    Node()
    {
        isEnd = 0;
        s = "";
        vec.resize(26, nullptr);
    }
};

class Trie
{
public:
    Node *head;
    Trie()
    {
        head = new Node();
    }
    void insert(string &s)
    {
        Node *tempHead = head;
        for (int i = 0; i < s.size(); i++)
        {
            if (tempHead->vec[s[i] - 'a'] == nullptr)
            {
                tempHead->vec[s[i] - 'a'] = new Node();
            }
            tempHead = tempHead->vec[s[i] - 'a'];
            tempHead->s = s.substr(0, i + 1);
        }
        tempHead->isEnd = 1;
    }
};
class Solution
{
public:
    Trie tr;
    set<string> ans;
    void dfs(vector<vector<char>> &board, int i, int j, Node *currHead)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#' || currHead == nullptr)
        {

            return;
        }
        currHead = currHead->vec[board[i][j] - 'a'];
        if (currHead != nullptr && currHead->isEnd)
        {
            ans.insert(currHead->s);
        }
        char c = board[i][j];
        board[i][j] = '#';
        dfs(board, i, j + 1, currHead);
        dfs(board, i, j - 1, currHead);
        dfs(board, i - 1, j, currHead);
        dfs(board, i + 1, j, currHead);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        for (auto &&i : words)
        {
            tr.insert(i);
        }
        ans.clear();
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                Node *tp = tr.head;
                dfs(board, i, j, tp);
            }
        }
        vector<string> toreturn;
        for (auto &&i : ans)
        {
            toreturn.push_back(i);
        }
        
        return toreturn;
    }
};
int main()
{
    
    return 0;
}