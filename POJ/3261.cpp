#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAXN 200005
#define INF 100000
using namespace std;
int N,k,p;
int a[MAXN],dif[MAXN];
int sa[MAXN],lcp[MAXN],r[MAXN+1];
int tmp[MAXN+1];
int b[MAXN];
int deq[MAXN];
int solve()
{
	int s=0,t=0;
	int n=N;
	for(int i=0;i<n;i++)
	{
		while(s<t&&lcp[deq[t-1]]>=lcp[i]) t--;
		deq[t++]=i;
		if(i-p+1>=0)
		{
			b[i-p+1]=lcp[deq[s]];
			if(deq[s]==i-p+1)
			{
				s++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-p;i++)
        ans=max(ans,b[i]);
    return ans;
}
bool compare_sa(int i,int j)
{
    if(r[i]!=r[j]) return r[i]<r[j];
    else
    {
        int ri=i+k<=N-1?r[i+k]:-1;
        int rj=j+k<=N-1?r[j+k]:-1;
        return ri<rj;
    }
}
void construct_sa(int *S,int *sa)
{
    int n=N;
    for(int i=0;i<=n;i++)
    {
        sa[i]=i;
        r[i]=i<n?S[i]:-1;
    }
    for(k=1;k<=n;k*=2)
    {
        sort(sa,sa+n+1,compare_sa);
        tmp[sa[0]]=0;
        for(int i=1;i<=n;i++)
        {
            tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
        }
        for(int i=0;i<=n;i++)
        {
            r[i]=tmp[i];
        }
    }
}
void construct_lcp(int *S,int *sa,int *lcp)
{
    int n=N;
    for(int i=0;i<=n;i++) r[sa[i]]=i;
    int h=0;
    lcp[0]=0;
    for(int i=0;i<n;i++)
    {
        int j=sa[r[i]-1];
        if(h>0) h--;
        for(;j+h<n&&i+h<n;h++)
        {
            if(S[j+h]!=S[i+h]) break;
        }
        lcp[r[i]-1]=h;
    }
}
int main()
{
    scanf("%d %d",&N,&p);
    p--;
    for(int i=0;i<N;i++)
        scanf("%d",&a[i]);
    construct_sa(a,sa);
    construct_lcp(a,sa,lcp);
    printf("%d\n",solve());
    return 0;
}
