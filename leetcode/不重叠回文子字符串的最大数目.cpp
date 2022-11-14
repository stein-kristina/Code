#include <bits/stdc++.h>
using namespace std;
#define N 1145

int maxPalindromes(string s, int k)
{
  int n = s.size();
  bool flag[n][n];
  memset(flag, false, sizeof(flag));
  for (int i = 0; i < n; i++)
  {
    flag[i][i] = true;
    int l = i - 1, r = i + 1;
    while (l >= 0 && r<n && s[l]==s[r]){
      flag[l][r] = true;
      l--;r++;
    }
    l=i;r=i+1;
    while (l >= 0 && r<n && s[l]==s[r]){
      flag[l][r] = true;
      l--;r++;
    }
  }//找出有多少回文串
  vector<int> dp(n+1,0);
  for(int i=1;i<=n;i++){
    dp[i]=dp[i-1];
    for(int j = i-k; j>=0 ;j--){
      if(flag[j][i-1]){
        dp[i] = max(dp[i],dp[j]+1);
      }
    }
  }
  return dp[n];
}
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
  vector<vector<int>> a;
  vector<int> b = {1, 11, 1, 8};

  system("pause");
  return 0;
}
