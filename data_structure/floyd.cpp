#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1060;
int n,t;
int s[N<<2],sl[N<<2];
void add(int j,int k){
	s[++t]=k;
	sl[t]=sl[j];
	sl[j]=t;
	return;
}
//老样子，先用邻接表
int ans;
bool num[N];
void dfs(int x,int y,int dep){
//	cout<<x<<" "<<dep<<endl;
	if(dep<=2) num[x]=1;
	bool flag=0;
	for(int i=sl[x];i;i=sl[i]){//查找它的邻接点
		int de=s[i];
		if(de==y) continue;
		dfs(de,x,dep+1);
//		cout<<x<<" "<<de<<" "<<num[de]<<" "<<flag<<endl;
		if(flag){
			num[de]=1;
		}
		if(!num[de]){
			num[x]=1;
			num[de]=1;
			flag=1;
			num[y]=1;
			++ans;
		}
	}
	return;
}
/*
7
1 2
2 3
2 4
4 5
4 6
5 7

*/
int main()
{
	int i,j,k;
	scanf("%d",&n);
	t=n;
	for(i=1;i<=n;++i) s[i]=i,sl[i]=0;
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		add(j,k);add(k,j);
	}
	for(i=1;i<=n;++i) num[i]=0;
	num[1]=1;
	dfs(1,0,0);
	printf("%d\n",ans);
  system("pause");
	return 0;
}
