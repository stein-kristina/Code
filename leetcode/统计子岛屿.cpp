#include<bits/stdc++.h>

using namespace std;

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
  int m = grid1.size() , n = grid1[0].size();
  int ans = 0;
  const int cord[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
  for(int i = 0 ; i< m ;i++){
    for(int j =0 ; j<n ;j++){
      if(grid2[i][j]){
        queue<pair<int,int>> Q;
        Q.emplace(i,j);
        bool f = true;//用于判断是否完全被grid1包围
        f = grid1[i][j] ? true : false;//第一个点
        grid2[i][j] = 0;
        while(!Q.empty()){
          auto p = Q. front();
          Q.pop();
          for(int k =0 ; k<4 ;k++){
            int ix = p.first +cord[k][0] , iy = p.second + cord[k][1];
            if(ix>=0 && ix<m && iy >=0 && iy<n && grid2[ix][iy]){
              if(! grid1[ix][iy]){
                f = false;
              }
              grid2[ix][iy] = 0;
              Q.emplace(ix,iy);
            }
          }
        }
        ans += f;
      }
    }
  }
  return ans;
}

int main(){
  vector<vector<int>> a,b;
  cout<<countSubIslands(a,b);
}