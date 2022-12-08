#include <iostream>                
#include <string.h>

using namespace std;

#define INF 0x3f
const int a = 2e4+5;

int n,m;
int q,p,w,road[a][a];
int dis[a];
int check = 0;

void BellmanFord()
{
    memset(dis,INF,sizeof(dis));

    dis[1] = 0;

    for(int x = 1; x <= n; x++)
    {
    	check = 0;
        for(int y = 1; y <= m; y++)
        {
            if(dis[y] > dis[x] + road[x][y])
            {
                dis[y] = dis[x] + road[x][y];
                check = 1;
            }
        }
        if(!check)
        {
        	break;
        }
    }
    //复杂度
}
int main()
{
    scanf("%d%d",&n,&m);

    memset(road,INF,sizeof(road));

    for(int x = 1; x <= m; x++)
    {
        scanf("%d%d%d",&q,&p,&w);

        road[q][p] = w;
    }

    BellmanFord();

    for(int x = 2; x <= n; x++)
    {
        printf("%d\n",dis[x]);
    }
}
