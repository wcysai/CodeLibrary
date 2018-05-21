#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<assert.h>
#define F first
#define S second
#define mp make_pair
#define MAXN 100005
#define INF 1000000000
using namespace std;
typedef pair<int,int> P;
int n,m,k;
int r[MAXN+1];
int sa[MAXN],lcp[MAXN];
int S[MAXN],T[MAXN];
int c[MAXN],t1[MAXN],t2[MAXN];
void construct_sa(int S[],int n,int *sa) 
{
    n++;
    int m=10005;
    int i,*x=t1,*y=t2;
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=S[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1) 
    {
        int p=0;
        for(i=n-k;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
        for(i=0;i<m;i++) c[i]=0;
        for(i=0;i<n;i++) c[x[y[i]]]++;
        for(i=0;i<m;i++) c[i]+=c[i-1];
        for(i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
        swap(x,y);
        p=1; x[sa[0]]=0;
        for(i=1;i<n;i++) 
            x[sa[i]]=y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
        if(p>=n) break;
        m=p;
    }
}
void construct_lcp(int S[],int n,int *lcp)
{
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
    while(scanf("%d%d%d",&n,&m,&k)==3)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&S[i]);
            S[i]+=2;
        }
        S[n]=1;
        for(int i=n+1;i<=n+m;i++)
        {
            scanf("%d",&S[i]);
            S[i]+=2;
        }
        n+=m+1;
        m=n-m-1;
        S[n]=0;
        construct_sa(S,n,sa);
        construct_lcp(S,n,lcp);
        int a=0,b=0;
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            if(lcp[i]<k) {if(b>0) ans+=a; a=0; b=0;}
            if(sa[i+1]<m) a++; 
            if(sa[i+1]>m) b++;
        }
        a=0,b=0;
        for(int i=0;i<=n;i++)
        {
            if(lcp[i]<k+1) {if(b>0) ans-=a; a=0; b=0;}
            if(sa[i+1]<m) a++; 
            if(sa[i+1]>m) b++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
