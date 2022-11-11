#include<bits/stdc++.h>
using namespace std;
#define N 1145

struct cmp {
public:
    bool operator()(const pair<int,int>& i, const pair<int,int>& j) {
        return i.first < j.first;
    }
};
int main()
{
  int n;
  cin>>n;
  int on =n;
  vector<pair<int,int>> light;
  while(on--){
    int p1,p2;
    cin>>p1>>p2;
    light.emplace_back(p1,p2);
  }
  sort(light.begin(),light.end());
  vector<int> remain(n , 1);//最多保留多少灯塔
  int ans = 1;
  for(int i=1 ; i<n ;i++){
    int pos = lower_bound(light.begin(),light.end(), make_pair(light[i].first-light[i].second,0), cmp()) - light.begin();
    //找到第一个被炸的
    pos--;//就是第一个没被炸的
    if(pos < 0){
      remain[i] = 1;
    }
    else{
      remain[i] = remain[pos]+1;
    }
    ans = max(ans,remain[i]);
  }
  //用总数减去最大保留的就是最小损坏的
  cout<< n -ans<<endl;
  system("pause");
  return 0;
}