#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		string a, b;
		cin>>a>>b;
		printf("%c", b[0]-'a'+'A');
		for(int i=1; i<b.size(); i++) printf("%c", b[i]);
		cout<<a<<endl;
	}
	return 0;
}
