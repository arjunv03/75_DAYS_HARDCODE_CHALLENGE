// https://leetcode.com/problems/word-ladder/description/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
class Solution
{
public:
    bool canMove(string &s1, string &s2)
    {
        int ct = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                ct++;
            }
        }
        return ct == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, bool> isVis;
        unordered_map<string, set<string>> mp;
        for (auto &&i : wordList)
        {
            for (auto &&j : wordList)
            {
                if (canMove(i, j))
                {
                    mp[i].insert(j);
                    mp[j].insert(i);
                }
            }
            if (canMove(beginWord, i))
            {
                mp[beginWord].insert(i);
            }
        }
        queue<string> q;
        int level = 0;
        q.push(beginWord);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto tp = q.front();
                q.pop();
                if (tp == endWord)
                {
                    return level +1;
                }
                if (isVis.find(tp) == isVis.end())
                {
                    for (auto &&nxt : mp[tp])
                    {
                        q.push(nxt);
                    }
                }
                isVis[tp] = 1;
            }
            level++;
        }
        return 0;
    }
};
int main()
{
    
    return 0;
}