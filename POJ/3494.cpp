#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<vector>
#include<assert.h>
#include<map>
#include<queue>
#include<stack>
#include<queue>
#include<deque>
#define MAXN 3005
#define MAXM 3005
using namespace std;
int n,m;
int h[MAXM][MAXN];
int L[MAXN],R[MAXN];
int st[MAXN];
int mat[MAXN][MAXM];
int solve(int x)
{
	int t=0;
	for(int i=0;i<n;i++)
	{
		while(t>0&&h[x][st[t-1]]>=h[x][i]) t--;
		L[i]=t==0?0:(st[t-1]+1);
		st[t++]=i;
	}
	t=0;
	for(int i=n-1;i>=0;i--)
	{
		while(t>0&&h[x][st[t-1]]>=h[x][i]) t--;
		R[i]=t==0?n:st[t-1];
		st[t++]=i;
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		res=max(res,h[x][i]*(R[i]-L[i]));
	}
	return res;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&mat[i][j]);
        memset(h,0,sizeof(h));
        for(int i=0;i<m;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(mat[j][i]==1)
                {
                    cnt++;
                    h[j][i]=cnt;
                }
                else h[j][i]=cnt=0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,solve(i));
        printf("%d\n",ans);
    }
    return 0;
}
