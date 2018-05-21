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
int N,k;
int a[MAXN],dif[MAXN];
int sa[MAXN],lcp[MAXN],r[MAXN+1];
int tmp[MAXN+1];
bool C(int k)
{
    int l=INF,r=-INF;
    for(int i=0;i<=N-1;i++)
    {
        l=min(l,sa[i]);
        r=max(r,sa[i]);
        if(r-l>k) return true;
        if(lcp[i]<k)
        {
            l=INF;
            r=-INF;
        }
    }
    return false;
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
    int n=N-1;
    for(int i=0;i<=n;i++)
    {
        sa[i]=i;
        r[i]=i<n?S[i]+1000:-1;
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
    int n=N-1;
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
    scanf("%d",&N);
    while(N>0)
    {
        for(int i=0;i<N;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<N-1;i++)
            dif[i]=a[i+1]-a[i];
        construct_sa(dif,sa);
        construct_lcp(dif,sa,lcp);
        int left=0,right=N;
        while(right-left>1)
        {
            int mid=(left+right)/2;
            if(C(mid)) left=mid; else right=mid;
        }
        printf("%d\n",left+1>=5?left+1:0);
        scanf("%d",&N);
    }
    return 0;
}
