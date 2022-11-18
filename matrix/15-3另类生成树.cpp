#include<bits/stdc++.h>
using namespace std;

#define N 40

int dot[N];
int edge[N][N];
int om;
vector<int> path; // dfs暴力找点
bool used[N];//标记使用的点
double I=9999999;
vector<int> love;

void dfs(int index, int m, int n, double nodesum);
void prim(int m,int n, double nodenum);
int main()
{
    int n, m;
    cin >> n >> m;
    while (n && m)
    {
        om=m;
        for (int i = 1; i <= n; i++)
        {
            cin >> dot[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> edge[i][j];
            }
        }
        //先dfs找m个点，然后prim计算
        I = 999999;
        love.clear();//初始化答案
        memset(used,0,sizeof(used));
        dfs(1, m, n, 0);

        for (auto &i : love)
        {
            cout << i << ' ';
        }
        cout << endl;
        cin >> n >> m;
    }
}
// path
void dfs(int index, int m, int n, double nodesum)
{
    if (!m)
    {
        // prim
        prim(om, n,nodesum);
        return;
    }
    if(index==n+1) return;
    for (int i = index; i <= n; i++)
    {
        path.push_back(i);
        used[i] = true;
        double next = nodesum + dot[i] * 1.0;
        dfs(i+1, m - 1, n, next);
        used[i] = false;
        path.pop_back();
    }
}
// int dot[N];
// int edge[N][N];
// vector<int> path; // dfs暴力找点
// bool used[N];//标记使用的点
void prim(int m,int n, double nodenum)
{
    double ans=0;
    vector<int> mid;//走过的点
    bool vis[N];
    memset(vis,0,sizeof(vis));
    mid.push_back(path[0]);//第一个点
    vis[path[0]] = true;
    while(mid.size() < m){
        int bian = INT_MAX;
        int minin = 0;
        for(auto &i : mid){
            for(int j=1 ; j<=n ; j++){
                if(used[j] && i!=j && !vis[j] &&edge[i][j] < bian){
                    //使用的点，并且有更小的边,并且没连过
                    bian = edge[i][j];
                    minin = j;
                }
            }
        }
        mid.push_back(minin);
        ans += bian;
        vis[minin] = true;
    }
    if(I*nodenum > ans){
        I = ans/nodenum;
        //path肯定是有序的
        love = path;
    }
    else if(I == ans/nodenum){
        love = min(love,path);
    }
}