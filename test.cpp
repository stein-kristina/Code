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

const int dx[8] = {0, 0, 1, -1};
const int dy[8] = {1, -1, 0, 0};
bool edge(int &x,int &y,int &m,int &n){
  return (x==0)||x==m-1||y==0||y==n-1;
}
int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
  int m =maze.size(), n =maze[0].size();
  if(edge(entrance[0],entrance[1],m,n)) return 1;

  queue<pair<int,int>> Q;
  Q.emplace(entrance[0],entrance[1]);
  maze[entrance[0]][entrance[1]] = '+';
  int step = 0;
  while(!Q.empty()){
    int siz = Q.size();
    while(siz--){
      auto p =Q.front();
      Q.pop();
      for(int i=0;i<4;i++){
        int x =p.first+dx[i],y=p.second+dy[i];
        if(x>=0 && x<m && y>=0 && y<n && maze[x][y]=='.'){
          if(edge(x,y,m,n)) return step+1;
          Q.emplace(x,y);
          maze[x][y] = '+';
        }
      }
    }
    step++;
  }
  return -1;
}
int main()
{

  system("pause");
  return 0;
}
