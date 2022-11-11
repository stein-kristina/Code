#include<bits/stdc++.h>
using namespace std;
#define N 1145
   static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int shortestPathAllKeys(vector<string>& grid) {
    struct State{
      int x;
      int y;
      int key;
    };//记录拥有的钥匙状态，拥有不同钥匙时候可以走回头路
    State start;
    start . key = 0;//初始拥有钥匙为0
    int keycnt = 0;
    int m = grid.size(), n = grid[0].size();
    for(int i =0 ;i<m;i++){
      for(int j=0; j<n ; j++){
        if(grid[i][j] == '@'){
          start.x = i;
          start.y = j;
        }
        else if(grid[i][j] >= 'a' && grid[i][j] <= 'z'){
            keycnt++;
        }
      }
    }
    int keyall = (1 << keycnt) - 1;//所有钥匙
    queue<State> Q;
    Q.push(start);
    vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(keyall+1,false)));
    int step = 0;
    while(!Q.empty()){
      int siz = Q.size();
      while(siz--){
        State cur = Q.front();
        Q.pop();
        if(cur.key == keyall) return step;
        for(int i = 0 ; i < 4 ;i++){
          int x = cur.x + dirs[i][0], y = cur.y + dirs[i][1];
                    if (x < 0 || y < 0 || x >= m || y >= n) continue;
                    
                    char c = grid[x][y];
                    int key = cur.key;
                    
                    if (c == '#') continue;
                    if (isupper(c) && (key >> (c - 'A') & 1) == 0) continue;
                    
                    if (islower(c)) {
                        key |= 1 << (c - 'a');
                    }
                    if (vis[x][y][key] == true) continue;
                    
                    vis[x][y][key] = true; 
                    Q.push(State{x, y, key}); 
        }
      }
      step++;
    }
    return -1;
}
int main()
{
  vector<string> a;
  cout<< shortestPathAllKeys(a);
  system("pause");
   return 0;
}