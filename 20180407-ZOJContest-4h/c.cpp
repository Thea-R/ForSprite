#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=300000+10;

int T, n, m, tot, a[maxn];
int fir[maxn], nxt[maxn], from[maxn], siz[maxn], tail[maxn];

void Add(int s, int v)
{
	if(siz[s]==0)
	{
		siz[s]++;
		fir[s]=tail[s]=++tot;
		nxt[tot]=from[tot]=-1;
		a[tot]=v;
	}
	else
	{
		siz[s]++;
		nxt[tail[s]]=++tot;
		from[tot]=tail[s];
		tail[s]=tot;
		a[tot]=v;
	}
	return ;
}

void Pop(int s)
{
	if(siz[s]==0)	printf("EMPTY\n");
	else
	{
		printf("%d\n", a[tail[s]]);

		--siz[s];
		if(siz[s])	tail[s]=from[tail[s]];
	}
	return ;
}

void Move(int s, int t)
{
	if(siz[t])
	{
		if(siz[s])
		{
			nxt[tail[s]]=fir[t];
			from[fir[t]]=tail[s];
			tail[s]=tail[t];
			siz[s]+=siz[t];

			siz[t]=0;
		}
		else
		{
			fir[s]=fir[t], tail[s]=tail[t], siz[s]=siz[t];
			siz[t]=0;
		}
	}
	return ;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &m);

		tot=0;
		for(int i=1; i<=n; i++)	siz[i]=0;

		for(int i=1, op, s, v, t; i<=m; i++)
		{
			scanf("%d", &op);
			if(op==1)
			{
				scanf("%d%d", &s, &v);
				Add(s, v);
			}
			else if(op==2)
			{
				scanf("%d", &s);
				Pop(s);
			}
			else
			{
				scanf("%d%d", &s, &t);
				Move(s, t);
			}
		}
	}
	return 0;
}
