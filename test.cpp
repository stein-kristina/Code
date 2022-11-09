#include <bits/stdc++.h>
using namespace std;
bool valid(int i,int j,int n){
  return i>=0 && i<n && j>=0 && j<n;
}
int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {\
  int ans = 0;
  vector<vector<int>> matrix(n,vector<int>(n,n));
  for(auto & m :mines){
    matrix[m[0]][m[1]] = 0;
  }
  for(int k=0 ; k<n ;k++){
    int left = 0 ,right = 0,up = 0 ,down = 0;
    for(int i = 0, j =n-1; i<n ; i++,j--){
      left = (matrix[k][i]==0) ? 0 : left+1;
      right= (matrix[k][j]==0) ? 0: right +1;
      up = (matrix[i][k]==0) ? 0:up+1;
      down = (matrix[j][k] == 0)? 0 : down+1;

      matrix[k][i] = min(matrix[k][i],left);
      matrix[k][j] = min(matrix[k][j] , right);
      matrix[i][k] = min(matrix[i][k],up);
      matrix[j][k] = min(matrix[j][k],down);
    }
  }
  return ans;
}
int main()
{
  vector<vector<int>> a = {{4,2}};
   cout<<orderOfLargestPlusSign(5,a);
   
   system("pause");
   return 0;
}