#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int t,n,d;
int num[MAXN][MAXN];
int s[MAXN];
int main()
{
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d",&n,&d);
		for(int j=0;j<n;j++)
			for(int k=0;k<d;k++)
			{
				scanf("%d",&num[j][k]);
				num[j][k]--;
			}
		memset(s,0,sizeof(s));
		for(int j=0;j<n;j++)
			for(int k=0;k<d;k++)
				s[k]=s[k]^num[j][k];
		bool f=true;
		for(int k=0;k<d;k++)
			if(s[k]!=0) f=false;
		if(!f) puts("Alice"); else puts("Bob");
	}
	return 0;
}