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
bool vis[22][22][22][22];
struct step
{
  int x1,y1;//paris
  int x2,y2;//helen
  step(int x1=0,int y1=0,int x2=0,int y2=0):x1(x1),y1(y1),x2(x2),y2(y2){}
};

bool ismeet(step & cur,int ax1,int ay1,int ax2,int ay2){

  if(cur.y1 == cur.y2 && ay2==ay1 && ax1==cur.x2 && ax2 == cur.x1) return true;
  if(cur.x1 == cur.x2 && ax2==ax1 && ay1==cur.y2 && ay2== cur.y1) return true;
  return false;
}
int main()
{
  int m,n;
  memset(vis,0,sizeof(vis));
  cin>>n>>m;
  vector<string> migong(n);
  for(int i=0;i<n;i++){
    cin>>migong[i];
  }
  string helen;
  cin>>helen;
  //下标映射，0paris北，1南，2西，3东
  step start;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(migong[i][j] == 'H'){
        start.x2 = i,start.y2 = j;
      }
      if(migong[i][j] == 'P'){
        start.x1=i,start.y1=j;
      }
    }
  }
  const int way[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
  //北南西东
  vector<vector<int>> choose;//helen走法
  for(int i=0;i<4;i++){
    switch (helen[i])
    {
    case 'N':{
      choose.push_back({-1,0});
      break;
    }
    case 'S':{
      choose.push_back({1,0});
      break;
    }
    case 'W':{
      choose.push_back({0,-1});
      break;
    }
    case 'E':{
      choose.push_back({0,1});
      break;
    }
    default:
      break;
    }
  }
  queue<step> Q;
  Q.push(start);
  vis[start.x1][start.y1][start.x2][start.y2] =1;
  int ans =0;
  // const int way[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//paris
  // //北南西东
  // vector<vector<int>> choose;//helen走法
  while(!Q.empty()){
    int siz = Q.size();
    if(ans>=255){
        cout<<"Impossible"<<endl;
        return 0;
    }
    while(siz--){
      auto p = Q.front();
      Q.pop();
        if(p.x1==p.x2 && p.y1==p.y2) {
          cout<<ans<<endl;
          system("pause");
          return 0;
        }
      for(int i=0;i<4;i++){
        int ax1 = p.x1 + way[i][0],ay1 = p.y1 + way[i][1];
        int ax2 = p.x2 + choose[i][0],ay2 = p.y2+ choose[i][1];
        
        if(vis[ax1][ay1][ax2][ay2]) continue;//走过 
        if(ax1 <0 || ax1>=n || ay1 <0 || ay1 >=m) continue;//坐标非法
        if(ax2 <0 || ax2>=n || ay2 <0 || ay2 >=m) continue;
        if(migong[ax1][ay1]=='!' || migong[ax2][ay2]=='!' ) continue;//岩浆
        if(migong[ax1][ay1]=='#'){
          continue;//不能走到岩石上
        }//paris不能走到岩石上
        if(migong[ax2][ay2] =='#'){
          ax2 = p.x2,ay2 =p.y2;
        }
        if(vis[ax1][ay1][ax2][ay2]) continue;
        if(ismeet(p,ax1,ay1,ax2,ay2)){
          cout<<ans+1<<endl;
          system("pause");
          return 0;
        }
        vis[ax1][ay1][ax2][ay2]=1;
        Q.push(step(ax1,ay1,ax2,ay2));
      }
    }
    ans++;
  }
  cout<<"Impossible"<<endl;
  system("pause");
  return 0;
}
