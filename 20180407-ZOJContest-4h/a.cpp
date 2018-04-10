#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100+10;

int T, n, m, a, b;

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d%d", &n, &m, &a, &b);
		
		int cnt=0;
		for(int i=1; i<=n; i++)
			for(int j=1, tp; j<=m; j++)
			{
				scanf("%d", &tp);
				if(!(a<=tp && tp<=b))	++cnt;
			}

		if(a>b)	printf("No Solution\n");
		else printf("%d\n", cnt);
	}
	return 0;
}
