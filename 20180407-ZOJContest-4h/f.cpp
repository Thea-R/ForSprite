#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long lint;
const int maxn=4000+10;

int T, k1, k2, c, s1, s2, tot;
struct node
{
	lint v, m;
	node(lint vv=0, lint mm=0)
	{
		v=vv, m=mm;
	}
	bool operator <(const node&t)const
	{
		return v*t.m==m*t.v ? m<t.m : v*t.m>m*t.v;
	}
}p[maxn];

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &k1, &k2, &c);
		scanf("%d%d", &s1, &s2);

		tot=s1+s2;
		for(int i=1, a, j=1; i<=s1; i++, j++)
		{
			scanf("%d", &a);
			p[j]=node(k1, a);
		}
		for(int i=1, a, j=s1+1; i<=s2; i++, j++)
		{
			scanf("%d", &a);
			p[j]=node(k2, a);
		}

		sort(p+1, p+1+tot);

		lint ans=0, cnt=(lint)c;
		for(int i=1; i<=tot; i++) if(cnt>p[i].m)
		{
			ans+=p[i].v*(cnt-p[i].m);
			cnt-=p[i].m;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
