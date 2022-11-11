#include<bits/stdc++.h>
using namespace std;
#define N 1145
int n,m;//初始列,行
int ams = 0;//阿莫斯，答案
int land[N][N],vis[N][N];
int mx[8]={-1,0,1,-1,1,-1,0,1};
int my[8]={-1,-1,-1,0,0,1,1,1};//记录x和y的偏移量
void dfs(int x, int y,int path){
  //对于一个位置，有两种选择，一个是加，另一个是不加
  if(y == n+1){
    dfs(x+1,1,path);//一行一行填
    return ;
  }
  if(x == m+1){
    ams = max(ams , path);
    return;
  }
  dfs(x , y+1,path);//不加
  if(!vis[x][y]){//没加过 
    //加
    //为什么不用bool，因为会有重叠情况
    for(int i =0 ; i<8 ; i++){
      vis[x+mx[i]][y+my[i]]++;
    }
    vis[x][y]++;
    dfs(x, y+1, path + land[x][y]);
    vis[x][y]--;
    for(int i =0 ; i<8 ; i++){
      vis[x+mx[i]][y+my[i]]--;
    }
  }
}
int main()
{
  
  cin >> m>> n;
  memset(land,0,sizeof(land));
  memset(vis,0,sizeof(vis));
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      //为了不判断边界，懒捏
      cin>>land[i][j];
    }
  }
  dfs(1,1,0);
  cout<<ams<<endl;
  
   return 0;
}