#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#define gid(x, y) ((x-1)*m+y)
#define mp(a, b) make_pair(a, b)
using namespace std;
const int maxn=100000+10, INF=0x7f7f7f7f;

int T, n, m, tot, a[maxn], dis[maxn];
int sx, sy, tx, ty;
bool vis[maxn];

int Work()
{
	if(sx==tx && sy==ty)	return 0;
	for(int i=1; i<=tot; i++) vis[i]=false, dis[i]=INF;

	queue<pair<int, int> > q;
	q.push(mp(sx, sy));
	dis[gid(sx, sy)]=0, vis[gid(sx, sy)]=true;

	while(!q.empty())
	{
		int x=q.front().first, y=q.front().second;
		int id=gid(x, y), xx, yy, iid;
		q.pop();

		if((dis[id]&1)==0)
		{
			if(a[id]==0)
			{
				xx=x-1, yy=y;
				iid=gid(xx, yy);
				if(xx>=1 && xx<=n && !vis[iid])
				{
					q.push(mp(xx, yy));
					dis[iid]=dis[id]+1, vis[iid]=true;
					if(xx==tx && yy==ty)	return dis[iid];
				}
				
				xx=x+1, yy=y;
				iid=gid(xx, yy);
				if(xx>=1 && xx<=n && !vis[iid])
				{
					q.push(mp(xx, yy));
					dis[iid]=dis[id]+1, vis[iid]=true;
					if(xx==tx && yy==ty)	return dis[iid];
				}
			}
			else
			{
				xx=x, yy=y-1;
				iid=gid(xx, yy);
				if(yy>=1 && yy<=m && !vis[iid])
				{
					q.push(mp(xx, yy));
					dis[iid]=dis[id]+1, vis[iid]=true;
					if(xx==tx && yy==ty)	return dis[iid];
				}
				
				xx=x, yy=y+1;
				iid=gid(xx, yy);
				if(yy>=1 && yy<=m && !vis[iid])
				{
					q.push(mp(xx, yy));
					dis[iid]=dis[id]+1, vis[iid]=true;
					if(xx==tx && yy==ty)	return dis[iid];
				}
			}
		}
		else
		{
			if(a[id]==0)
			{
				xx=x, yy=y-1;
				iid=gid(xx, yy);
				if(yy>=1 && yy<=m && !vis[iid])
				{
					q.push(mp(xx, yy));
					dis[iid]=dis[id]+1, vis[iid]=true;
					if(xx==tx && yy==ty)	return dis[iid];
				}
				
				xx=x, yy=y+1;
				iid=gid(xx, yy);
				if(yy>=1 && yy<=m && !vis[iid])
				{
					q.push(mp(xx, yy));
					dis[iid]=dis[id]+1, vis[iid]=true;
					if(xx==tx && yy==ty)	return dis[iid];
				}
			}
			else
			{
				xx=x-1, yy=y;
				iid=gid(xx, yy);
				if(xx>=1 && xx<=n && !vis[iid])
				{
					q.push(mp(xx, yy));
					dis[iid]=dis[id]+1, vis[iid]=true;
					if(xx==tx && yy==ty)	return dis[iid];
				}
				
				xx=x+1, yy=y;
				iid=gid(xx, yy);
				if(xx>=1 && xx<=n && !vis[iid])
				{
					q.push(mp(xx, yy));
					dis[iid]=dis[id]+1, vis[iid]=true;
					if(xx==tx && yy==ty)	return dis[iid];
				}
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		tot=n*m;

		for(int i=1; i<=tot; i++) scanf("%d", &a[i]);

		scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
		printf("%d\n", Work());
	}
	return 0;
}
