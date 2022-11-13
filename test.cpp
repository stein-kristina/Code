#include<bits/stdc++.h>
using namespace std;
#define N 1145





int maxPalindromes(string s, int k) {
    int n = s.size();
    int ans=0;
    unordered_set<int> up,down;
    for(int i=0;i<n;i++){
      if(k==1){
        ans++;
        up.insert(i);
        down.insert(i);
      } 
      if(i && i<n-1 && s[i-1]==s[i+1]){
        if(down.find(i-1) != down.end()) continue;//有重叠
        if(k<=3){
          ans++;
          break;
        }//第一类情况
        int l = 2;
        while(i-l >0 && i + l <n && s[i-l]==s[i+l]){
          if(down.find(i-1) != down.end()) break;
          l++;
        //长度为5,7.。。
        }
        down.insert(i+l-1);//右边界
        i= i+l-1-1;
        ans++;
      }
      else if(i<n-1 && s[i]==s[i+1]){
        if(down.find(i) != down.end() || down.find(i+1) != down.end()) continue;//有重叠
        if(k<=2){
          ans++;
          break;
        }
        int l = 1;
        while(i-l>0 && i+1 +l <n && s[i-l]==s[i+1+l]){
          l++;
        }
        down.insert(i+l);//右边界
        i= i+1+l-1;
        ans++;
        //长度为4,6.。
      }
    }
    return ans;
}
struct TreeNode {
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
  vector<int> b={1,11,1,8};
  cout<<subarrayLCM(b,11);
  system("pause");
  return 0;
}
