#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int n;
set<string> fir[2], sec[2], vp;

int find(int d, string s)
{
	int cnt=0;
	for(set<string>::iterator it=sec[d].begin(); it!=sec[d].end(); it++)
	{
		string t=*it;
		if(t.find(s)!=-1)	++cnt;
	}
	return cnt;
}

int main()
{
	scanf("%d", &n);

	for(int i=1; i<=n; i++)
	{
		string a, b;
		cin>>a>>b;
		if(b[b.size()-1]=='i')//Korean
		{
			fir[0].insert(a);
			sec[0].insert(b);
		}
		else//Janpanese
		{
			fir[1].insert(a);
			sec[1].insert(b);
		}
	}
	
	printf("ssi-set %d\n", (int)fir[0].size());
	for(set<string>::iterator it=fir[0].begin(); it!=fir[0].end(); it++)	cout<<"\""<<*it<<"\",";
	cout<<endl;
	
	printf("san-set %d\n", (int)fir[1].size());
	for(set<string>::iterator it=fir[1].begin(); it!=fir[1].end(); it++)	cout<<"\""<<*it<<"\",";
	cout<<endl;
	
	int c0=sec[0].size();
	int c1=sec[1].size();
	
	string s;
	while(cin>>s)	vp.insert(s);
	
	cout<<vp.size()<<endl;
	for(set<string>::iterator it=vp.begin(); it!=vp.end(); it++)	cout<<"\""<<*it<<"\",";
	cout<<endl;

	cout<<c0<<endl;
	for(set<string>::iterator it=vp.begin(); it!=vp.end(); it++)	cout<<find(0, *it)<<',';
	cout<<endl;

	cout<<c1<<endl;
	for(set<string>::iterator it=vp.begin(); it!=vp.end(); it++)	cout<<find(1, *it)<<',';
	cout<<endl;
	return 0;
}
