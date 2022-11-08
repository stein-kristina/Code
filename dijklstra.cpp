#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;
 
#define N 1145

typedef struct _Node{
  int head;//顶点
  unordered_map<int,int> mp;//左int为邻接点，右int为权值
  _Node(int h):head(h){}
}Node;

vector<Node> arr;//存放所有点的集合 
int dis[N];//计算最短距离
int path[N];//找前驱节点
unordered_set<int> visit;//还没走过的顶点

void dijkstra(int start, int n);

int main(){
  int n,m;
  cout<<"输入图的顶点数和边数：";
  cin>>n>>m;
  for(int i=0;i<N;i++) dis[i] = INT_MAX;
  memset(path , 0 ,N*sizeof(int));
  cout<<"请输入各个顶点：";
  int on = n;
  while(on--){
    int p;
    cin>>p;
    arr.push_back(Node(p));
    visit.insert(p);
  }
  int om = m;
  while(om--){
    int a,b,c;
    cin>>a>>b>>c;
    arr[a].mp[b]=c;
  }
  int st;
  cin>>st;
  dijkstra(st,n);
  for(int i=0;i<n;i++){
    if(dis[i] == INT_MAX){
      cout<<st<<"不可到达"<<i<<endl;
      continue;
    }
    cout<<st<<"到"<<i<<"的最短路程是"<<dis[i]<<' ';
    cout<<endl;
    cout<<"路径是";
    string s;
    for(int j = path[i]; j!=-1 ; j = path[j]){
      s+= ">-"+to_string(j) ;
    }
    reverse(s.begin(),s.end());
    cout<<s<<i;
    cout<<endl;
  }

  system("pause");
}
// vector<Node> arr;//存放所有点的集合 
// int dis[101];//计算最短距离
// int path[101];//找前驱节点
void dijkstra(int start, int n){
  //start的意思是从那个点开始计算到剩下点的最短路径,执行n次找到所有点
  dis[start] = 0;
  path[start] = -1;//终止
  int bef = start,befpath = 0;
  visit.erase(start);//记录已经选择的节点
  for(int i=1;i<n;i++){
    auto &p = arr[bef].mp;
    int minin=0;
    for(auto it=p.begin() ; it != p.end() ;it++){
      if(befpath + it->second < dis[it->first]){
        dis[it->first] =  befpath + it->second;
        path[it->first] = bef;//前驱节点
      }
    }
    
    int mindis = INT_MAX;
    for(auto &i : visit){
         //新节点
        if(dis[i] < mindis){
          mindis = dis[i];
          minin = i;
        }
    }
    //到他的最小距离
    if(mindis == INT_MAX){
      //剩下的点都不可达了
      break;
    }
    visit.erase(minin);
    bef = minin;
    befpath = mindis;
  }
}