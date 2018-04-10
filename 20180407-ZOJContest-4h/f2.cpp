#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=2000+10;
typedef long long lint;

int T, s1, s2, c;
lint a1, a2, sum1[maxn], sum2[maxn];
lint dp[maxn][maxn];

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld%d", &a1, &a2, &c);
		scanf("%d%d", &s1, &s2);

		for(int i=1; i<=s1; i++)	scanf("%lld", &sum1[i]);
		sort(sum1+1, sum1+s1+1);
		for(int i=1; i<=s1; i++) sum1[i]+=sum1[i-1];
		
		for(int i=1; i<=s2; i++)	scanf("%lld", &sum2[i]);
		sort(sum2+1, sum2+s2+1);
		for(int i=1; i<=s2; i++) sum2[i]+=sum2[i-1];

		dp[0][0]=0;

		lint ans=0;
		for(int i=1; i<=s1; i++)	dp[i][0]=max(dp[i-1][0], dp[i-1][0]+a1*(c-sum1[i])), ans=max(ans, dp[i][0]);
		for(int i=1; i<=s2; i++)	dp[0][i]=max(dp[0][i-1], dp[0][i-1]+a2*(c-sum2[i])), ans=max(ans, dp[0][i]);

		for(int i=1; i<=s1; i++)
			for(int j=1; j<=s2; j++)
			{
				dp[i][j]=max(dp[i][j-1]+a2*(c-sum1[i]-sum2[j]), dp[i-1][j]+a1*(c-sum1[i]-sum2[j]));
				ans=max(ans, dp[i][j]);
			}

		printf("%lld\n", ans);
	}
	return 0;
}
