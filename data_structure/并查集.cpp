#include <bits/stdc++.h>
using namespace std;

//并查集:
int find(vector<int> & parent,int index){
  int i = index;
  while(parent[index] >= 0){
    index = parent[index];
  }
  return index;
}//返回根节点
void unionroot(vector<int> & parent, int r1,int r2){
  int root1 = find(parent,r1), root2= find(parent,r2);
  if(root1 != root2){//两个根不一样
    parent[root2] = root1;
    many--;
  }
}
int many;//连通分支个数

//lc1319题:
int findCircleNum(vector<vector<int>> &isConnected)
{
  int city = isConnected.size();
  vector<int> par(city,-1);//初始化并查集
  for(int i = 0;i < city ;i++){
    for(int j= i+1 ; j<city ;j++){
      if(isConnected[i][j])//有边
      unionroot(par,i,j);
    }
  }
  int ans = 0;
  for(int i=0; i<city ;i++){
    if(par[i] == -1){
      ans++;
    }
  }
  return ans;
}

int main()
{
  vector<vector<int>> a = {{1,1,0},{1,1,0},{0,0,1}};
  vector<int> b = {5, 3, 11, 19, 2};
  cout<<findCircleNum(a);
  system("pause");
  return 0;
}
