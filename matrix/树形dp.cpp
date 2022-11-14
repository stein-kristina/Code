#include <bits/stdc++.h>
using namespace std;
#define N 4000
// struct Node{
//   unordered_set<int> edge;//我儿子
//   Node(){}
// };
vector<unordered_set<int>> dad;//邻接表
bool light[N];
int ans = 0;
void dfstree(int x,int y,int dep){//y是x的爹
  if(dep<=2) light[x]=true;//与根节点距离小于等于2的先点了
  bool f = false;//判断x有没有被点亮
  for(auto it = dad[x].begin();it != dad[x].end();it++){
    int son = *it;
    if(son == y) continue;
    dfstree(son,x,dep+1);
    if(f){//爹亮了
      light[son] = true;
    }
    if(!light[son]){
      //儿子没亮！那就把儿子连上吧
      light[son] = true;
      light[x] = true;
      f = true;
      light[y] = true;//把爹的爹点了，因为距离还在2内
      ans++;
    }
  }
}
int main()
{
  int t;
  cin>>t;
  dad.resize(t+1);//初始化
  memset(light,0,sizeof(light));
  --t;
  while(t--){
    int l,r;
    cin>>l>>r;
    dad[l].insert(r);//l是r的父亲
    dad[r].insert(l);
  }
  dfstree(1,0,0);
  cout<<ans<<endl;
  system("pause");
  return 0;
}
