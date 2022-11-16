#include<iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <cmath>
#include <list>
#include<algorithm>
#include<string>
using namespace std;

void getnext(vector<int> &next, string &s){
  int j = 0,m=s.size();
  next[0] = 0;
  for(int i=1;i<m;i++){
    while(j && s[j] != s[i]){
      j = next[j-1];
    }
    if(s[j] == s[i]){
      j++;
    }
    next[i] = j;
  }
}

int match(string &fa,string &son){
  int n=fa.size(),m=son.size();
  vector<int> next(m,0);
  getnext(next,son);
  int j = 0;
  for(int i=0;i<n;i++){
    while(j && fa[i] != son[j]){
      j = next[j-1];
    }
    if(fa[i] == son[j]){
      j++;
    }
    if(j == m) return 114514;
  }
  return -1;
}

int main(){
  string father;
  string son;
  cin>>father>>son;
  cout<<match(father,son);
  system("pause");
}