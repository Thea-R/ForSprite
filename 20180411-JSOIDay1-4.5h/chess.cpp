#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=2048+10, N=10+5, INF=0x7f7f7f7f;
#define mp(a, b) make_pair(a, b)

int n, m, f[maxn][maxn], a[N][N], b[N][N];

int Dfs(int row, int col, int d)//行状态为row、列状态为col，现在轮到第d个人的最优解
{
	if(f[row][col]!=INF)	return f[row][col];
	if(row+col==0)	return f[row][col]=0;

	bool vis[N][N]={0};
	int ans=0, cx=0, x[N], cy=0, y[N];
	for(int tp=row, i=n; tp; i--, tp>>=1) if(tp&1)	x[++cx]=i;
	for(int tp=col, j=m; tp; j--, tp>>=1) if(tp&1)	y[++cy]=j;
	for(int i=cx, j=1; j<=cy; i--, j++)	vis[x[i]][y[j]]=true;

	if(d==0)	ans=-INF;
	else ans=INF;
	for(int i=cx, j=1, xx, yy, tr, tc; j<=cy; i--, j++)
	{
		xx=x[i], yy=y[j];
		tr=(row^(1<<(n-xx))), tc=(col^(1<<(m-yy)));

		if(xx+1<=n)
		{
			bool ok=true;
			for(int p=1; p<=yy-1; p++) if(vis[xx+1][p])
			{
				ok=false;
				break;
			}
			if(ok)
			{
				tr=(tr|(1<<(n-xx-1)));
				tc=(tc|(1<<(m-yy)));
			}
		}

		if(yy+1<=m)
		{
			bool ok=true;
			for(int p=1; p<=xx-1; p++) if(vis[p][yy+1])
			{
				ok=false;
				break;
			}
			if(ok)
			{
				tr=(tr|(1<<(n-xx)));
				tc=(tc|(1<<(m-yy-1)));
			}
		}
		
		int tans=Dfs(tr, tc, d^1);
		if(d==0)	ans=max(ans, a[xx][yy]+tans);
		else ans=min(ans, -b[xx][yy]+tans);
	}

	return f[row][col]=ans;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d", &a[i][j]);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d", &b[i][j]);
	memset(f, 0x7f, sizeof f);
	printf("%d\n", Dfs((1<<(n-1)), (1<<(m-1)), 0));
	return 0;
}
