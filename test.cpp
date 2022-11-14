#include <bits/stdc++.h>
using namespace std;
#define N 1145

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int total;//整个数组的和
int len;//整个数组的长度

bool dfs(int index , int sum, int siz ,vector<int>& nums){
  if(index == len-1){
    if(sum*len == siz*total) return true;
    return false;
  }
  for(int i = index;i < len-1 ;i++){//len-1非空
    sum+=nums[i];//目前的和
    siz++;//长度
    if(sum*len > siz*total) return false;//已经比它大了，再找下去没结果，剪枝
    if(sum*len == siz*total || dfs(i+1,sum,siz,nums)){
      return true;
    }
    siz--;
    sum-=nums[i];
  }
  return false;
}
// bool splitArraySameAverage(vector<int>& nums) {
//   sort(nums.begin(),nums.end());
//   len = nums.size();
//   total=0;
//   for(int i=0;i<len;i++) total+=nums[i];
//   return dfs(0,0,0,nums);
// }
bool splitArraySameAverage(vector<int> &nums) {
        int n = nums.size(), m = n / 2;
        if (n == 1) {
            return false;
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int &x : nums) {
            x = x * n - sum;
        }

        unordered_set<int> left;
        for (int i = 1; i < (1 << m); i++) {
            int tot = 0;
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    tot += nums[j];
                }
            }
            if (tot == 0) {
                return true;
            }
            left.emplace(tot);
        }

        int rsum = accumulate(nums.begin() + m, nums.end(), 0);
        for (int i = 1; i < (1 << (n - m)); i++) {
            int tot = 0;
            for (int j = m; j < n; j++) {
                if (i & (1 << (j - m))) {
                    tot += nums[j];
                }
            }
            if (tot == 0 || (rsum != tot && left.count(-tot))) {
                return true;
            }
        }
        return false;
}

int main()
{
  vector<vector<int>> a={{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
  vector<int> b = {5,3,11,19,2};
  cout<<splitArraySameAverage(b);

  system("pause");
  return 0;
}
