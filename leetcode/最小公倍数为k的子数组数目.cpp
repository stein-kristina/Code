#include<bits/stdc++.h>
using namespace std;
#define N 1145

//就是不断地对他们求最小公倍数
//给一个arr,arr[i]与之前的数的最小公倍数为（arr[i-1]与之前的最小公倍数）与arr[i]的最小公倍数

//最大公因数就是，给定一个arr，arr[i]与后面所有数最大公因子都为k，那么他们整个子数组的最大公因子就是k
int getGcd(int a,int b){
	int c;
	while(b){
		c=a;
		a=b;
		b=c%b;
	}
	return a;
}
int subarrayLCM(vector<int>& nums, int k) {
    int ans = 0;
    int n =nums.size();
    for(int i=0;i<n;i++){
      int bef = nums[i];
      int cur = i;
      int gong = bef * nums[cur] /getGcd(bef,nums[cur]);
      if(gong > k) continue;
      if(gong == k ) ans++;
      while(cur<n){
        bef = gong;
        cur++;
          if(cur >=n) break;
        gong = bef * nums[cur] /getGcd(bef,nums[cur]);
        if(gong == k) ans++;
        else if(gong > k) break;
      }
    }
    return ans;
}
int main()
{
  vector<vector<int>> a;
  vector<int> b={1,11,1,8};
  cout<<subarrayLCM(b,11);
  system("pause");
  return 0;
}
