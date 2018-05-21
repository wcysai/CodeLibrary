#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int num[1001],ans,t;
int main()
{
	ans=0;t=-1;
	memset(num,0,sizeof(num));
	for(int i=1;i<=1000;i++)
		for(int j=i;i*i+j*j<=1000000;j++)
		{
			int len=sqrt(i*i+j*j);
			if(len*len!=i*i+j*j||i+j+len>1000) continue;
			printf("%d %d %d\n",i,j,len);
			num[i+j+len]++;
			if(num[i+j+len]>ans)
			{
				ans=num[i+j+len];
				t=i+j+len;
			}
		}
	printf("%d\n",t);
	return 0;
}	