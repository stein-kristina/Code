#include <random>
#include <bits/stdc++.h>

using namespace std;

int minMoves(vector<int> &nums, int k)
{
  // 前缀和左右移动
  int n = nums.size();

  vector<int> pos1;
  for (int i = 0; i < n; i++)
  {
    if (nums[i])
      pos1.push_back(i - pos1.size());
  }
  int m = pos1.size();
  vector<int> pre(m + 1, 0);
  for (int i = 0; i < m; i++)
  {
    pre[i + 1] = pre[i] + pos1[i];
  }
  int ans = INT_MAX;
  for (int i = 0; i <= m - k; i++)
  {
    ans = min(ans, pre[i] + pre[i + k] - 2 * pre[i + k / 2] - pos1[i + k / 2] * (k & 1));
  }
  return ans;
}
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
  vector<vector<int>> adj(n);
  for(auto & pr : edges){
    adj[pr[0]].push_back(pr[1]);
    adj[pr[1]].push_back(pr[0]);
  }
  queue<int> Q;
  vector<bool> vis(n,false);
  Q.push(source);vis[source]= true;
  while(!Q.empty()){
    int siz = Q.size();
    while(siz--){
      auto p = Q.front();
      Q.pop();
      if(p == destination) return true;
      for(auto &child : adj[p]){
        if(!vis[child]){
          Q.push(child);
        }
      }
    }
  }
  return false;
}
int main()
{
  vector<int> a = {1, 3, 2};
  vector<vector<int>> g = {{1, 2}, {1, 3}, {1, 4}};

  system("pause");
  return 0;
}