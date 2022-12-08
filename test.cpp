#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int dfs(int index,vector<int> &ans,vector<vector<int>> &adj,vector<int> &quiet){
  int n = quiet.size();
  int retmin = index;//下标
  int nummin = quiet[index];
  for(int &son : adj[index]){
    if(ans[son] == INT_MAX){
      int his = dfs(son,ans,adj,quiet);//返回最小的quiet
      if(nummin > his){
        nummin = his;
        retmin = ans[son];
      }
    }
    else{
      if(nummin > quiet[ans[son]]){
        nummin = quiet[ans[son]];
        retmin = ans[son];
      }
    }
  }//ans[son]那个的最小的
  ans[index] = retmin;//下标
  return nummin;
}
vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
{
  int n = quiet.size();
  vector<int> ans(n,INT_MAX);
  vector<vector<int>> adj(n);
  for(auto & pr : richer){
    adj[pr[1]].push_back(pr[0]);
  }
  for(int i=0 ; i<n ; i++){
    if(ans[i] == INT_MAX){
      dfs(i,ans,adj,quiet);
    }
  }
  return ans;
}

int main()
{
  vector<int> a = {3,2,5,4,6,1,7,0}, b = {6, 2, 6, 6, 1, 1, 4, 6, 4, 6, 2, 5, 4, 2, 1};
  int tar = 10;
  vector<vector<int>> c = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
  auto d = loudAndRich(c,a);
  system("pause");
  return 0;
}
