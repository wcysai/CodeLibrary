#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#define MAXN 10005
#define INF 1000000000
using namespace std;
int t;
char str[MAXN];
int cnt[26];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		int n=strlen(str);
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
			cnt[str[i]-'a']++;
		int res=0;
		for(int i=0;i<26;i++)
			res+=cnt[i]&1;
		if(res>1) {printf("Impossible\n"); continue;}
		int ans=0;
		for(int i=0;i<n/2;i++)
		{
			int lb=i,rb=n-1-i;
			int p=INF,q=INF;
			for(int j=lb;j<rb;j++)
				if(str[j]==str[rb])
				{
					p=j-lb;
					break;
				}
			for(int j=rb;j>lb;j--)
				if(str[j]==str[lb])
				{
					q=rb-j;
					break;
				}
			//printf("%d %d\n",p,q);
			if(p<=q)
			{
				ans+=p;
				char c=str[p+lb];
				for(int j=p+lb;j>lb;j--)
					str[j]=str[j-1];
				str[lb]=c;
			}
			else
			{
				ans+=q;
				char c=str[rb-q];
				for(int j=rb-q;j<rb;j++)
					str[j]=str[j+1];
				str[rb]=c;
			}
			//printf("%s\n",str);
		}
		printf("%d\n",ans);
	}
	return 0;
}