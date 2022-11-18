#include <bits/stdc++.h>
using namespace std;
#define N 4000
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
//终端节点
/*
本人思路从0往外扩散bfs搜索，因为有正边，逆边，需要先做预处理，
正边赋权值1，逆边赋权值0，（解释：正边就是题目给的边，逆边就是把
给的边的方向逆转一下，因为从0开始搜索，如果是沿着搜索方向的话，则
需要把这条边翻转过来，则权值为1，如果是和搜索方向相反的话，则不需要
把这条边翻转，则权值为0。）然后bfs搜索的过程中叠加答案就可以了。
*/
int minReorder(int n, vector<vector<int>> &connections)
{
  int res = 0;
  vector<vector<pair<int, int>>> nums(n);
  for (auto &cur : connections)
  {
    int from = cur[0];
    int to = cur[1];
    nums[from].push_back({to, 1});
    nums[to].push_back({from, 0});
  }
  queue<int> q;
  vector<bool> visit(n,false);
  q.push(0);
  visit[0] = 1;
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    for (auto &temp : nums[cur])
    {
      if (!visit[temp.first])
      {
        res += temp.second;
        q.push(temp.first);
        visit[temp.first] = 1;
      }
    }
  }
  return res;
}

int main()
{
  vector<int> a = {5, 9, 6, 10, -1, 8, 9, 1, 9, 3, 4};
  vector<int> b = {0, 213, 0, 253, 686, 170, 975, 0, 261, 309, 337};
  vector<vector<int>> c = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
  vector<string> e = {"a", "bb", "acd", "ace"};

  system("pause");
  return 0;
}
