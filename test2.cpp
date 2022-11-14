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
  vector<unordered_set<int>> m(2);
  m[0].insert(1);
  cout<<*m[0].begin();
  system("pause");
  return 0;
}
