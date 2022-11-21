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

vector<vector<int>> adj;//邻接表
long long gas = 0;//总耗油量
bool vis[100000];
int dfs(int index,int &n,int &seats){//int返回座位数字，n是点的个数
  if(index == n) return 0;
  if(adj[index].size()==1){
    vis[index]=true;
    return seats-1;
  }
  int sit = 0;//还剩多少座位
  vis[index] =true;
  for(auto &it : adj[index]){
    if(vis[it]) continue;
    sit += dfs(it,n,seats);
    gas += seats-sit;
  }
  if(sit > 0){
    sit--;
  }
  else if(sit == 0){
    return seats-1;
  }
  return sit;
}
long long minimumFuelCost(vector<vector<int>> &roads, int seats)
{
  memset(vis,0,sizeof(vis));
  int n =roads.size();
  adj.resize(n+1);
  for(int i=0;i<roads.size();i++){
    int p1 = roads[i][0], p2=roads[i][1];
    adj[p1].push_back(p2);
    adj[p2].push_back(p1);
  }
  dfs(0,n,seats);
  return gas;
}
int main()
{
  vector<vector<int>> a={{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}};
  cout<<minimumFuelCost(a,2);
  system("pause");
  return 0;
}
