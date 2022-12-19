#include <bits/stdc++.h>

using namespace std;

#define N 250

int dis[N];     // 计算最短距离
int path[N];    // 找前驱节点
int edge[N][N]; // 边的权值

void dijkstra(int start, int n);
void init(int n)
{
  for (int i = 1; i <= n; i++)
  {
    dis[i] = INT_MAX;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      edge[i][j] = INT_MAX;
      if (i == j)
        edge[i][j] = 0;
    }
  }
}
int main()
{

  int n, m;
  cin >> n >> m;
  init(n);
  int om = m;
  int a, b, c;
  while (om--)
  {
    cin>>c;
    cin >> a >> b >> c;
    edge[a][b] = min(edge[a][b], c);
    edge[b][a] = edge[a][b];
    b++;
    if(b > n){
      a++;
      b= a+1;
    }
  }
  dijkstra(1, n);
  if (dis[n] == INT_MAX)
  {
    cout << -1 << endl;
  }
  else
    cout << dis[n] << endl;
}
// vector<Node> arr;//存放所有点的集合
// int dis[101];//计算最短距离
// int path[101];//找前驱节点
struct node
{
  int u, dis; // u 是当前点的编号， dis是u点距离起点st的距离
  node() {}
  node(int _u, int d) : u(_u), dis(d) {}
  bool operator<(const node &b) const
  {
    return dis > b.dis;
  }
};

void dijkstra(int start, int n)
{
  dis[start] = 0;
  priority_queue<node> Q;
  Q.push(node(start, 0));
  vector<bool> vis(n + 1, 0);
  path[start] = -1;
  while (!Q.empty())
  {
    int u = Q.top().u;
    Q.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    for (int v = 1; v <= n; v++)
    { // 以u为中介点，看看是否可以更新尚未访问过的点到起点的距离
      // v未被访问过、u可以到达v、从u去往v距离更小
      if (!vis[v] && edge[u][v] != INT_MAX && dis[v] > dis[u] + edge[u][v])
      {
        dis[v] = dis[u] + edge[u][v]; // 更新d[v]
        path[v] = u;
        Q.push(node(v, dis[v])); // 将v及d[v]入队
      }
    }
  }
}