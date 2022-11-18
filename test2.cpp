#include <bits/stdc++.h>
using namespace std;
#define N 4000
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int main()
{
  unordered_map<int,int> m;
  
  auto it = m.find(0);
  if(it!= m.end()){
    m[0] = min(m[0] , 0);
  }
  m[1]=max(m[1],2);
  cout<<m[0];
  system("pause");
  return 0;
}
