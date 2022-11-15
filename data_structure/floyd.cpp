#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXVEX 1000
const int N=1000;

typedef struct
{
	char vexs[MAXVEX];//顶点表
	int arc[MAXVEX][MAXVEX];//邻接矩阵
	int numVertexte;//当前顶点数
	int numEdges;//当前边数
}MGraph;

int dis[N][N];//距离
int P[N][N];//路径
int n;//顶点个数
void floyd(){
  for(int i=0;i<n;i++){
    //最外层枚举各个顶点
    for(int j=0 ; j<n ;j++){
      for(int k=0; k<n ;k++){
        if(dis[j][k] > dis[j][i]+dis[i][k]){
          dis[j][k] = dis[j][i] + dis[i][k];
          P[j][k] = P[j][i];
        }
      }
    }
  }
}
void init(){
  for(int i=0; i<n ;i++){
    for(int j=0 ; j<n ;j++){
      cin>>dis[i][j];
      if(i==j) dis[i][i] = 0;
      P[i][j] = j;
    }
  }
}
void findpath(int x,int y){
  //找到x到y的最短路径
  cout<<"最短距离是:"<<dis[x][y]<<endl;
  string s;
  while(P[x][y] != y){
    s+=to_string(x)+"->";
    x = P[x][y];
  }
  s+= to_string(y);
  cout<<s<<endl;
}
int main()
{
  memset(dis,INT_MAX,sizeof(dis));
  memset(P,0,sizeof(P));
	//输入最初的矩阵信息
  system("pause");
	return 0;
}
