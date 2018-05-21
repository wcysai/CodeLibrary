#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define INF 1000000
using namespace std;
char DNA[1000][1000];
int sn[1000];
int main()
{
	int n,m,cnt,mini,t;
	memset(sn,0,sizeof(sn));
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	  scanf("%s",DNA[i]);
	for(int i=0;i<m;i++)
	{
		cnt=0;
		for(int j=0;j<n;j++)
		  for(int k=j+1;k<n;k++)
		    if (DNA[i][j]>DNA[i][k]) cnt++;
		sn[i]=cnt;
	}
	 for(int i=0;i<m;i++)
	 {
	 	mini=INF-1;
	    t=0;
	    for(int j=0;j<m;j++)
	    {
	 	if(mini>sn[j])
	 	{
	        mini=sn[j];
	        t=j;
		 }
	    }
		 printf("%s\n",DNA[t]);
		 sn[t]=INF;
	 }
	 return 0;
 } 