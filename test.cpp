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

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool isIdealPermutation(vector<int> &nums)
{
  int n =nums.size();
  int your = nums[0];
  for (int i = 2; i < n; i++)
  {
    if(your > nums[i]) return false;
    your = max(your , nums[i-1]);
  }
  return true;
}

int main()
{
  vector<int> a = {2, 0, 1};
  cout << isIdealPermutation(a);
  system("pause");
  return 0;
}
