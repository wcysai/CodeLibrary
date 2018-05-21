#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAXN 1005
using namespace std;
int n,k,t;
int sa[MAXN+1],lcp[MAXN+1],r[MAXN+1];
int tmp[MAXN+1];
bool compare_sa(int i,int j)
{
    if(r[i]!=r[j]) return r[i]<r[j];
    else
    {
        int ri=i+k<=n?r[i+k]:-1;
        int rj=j+k<=n?r[j+k]:-1;
        return ri<rj;
    }
}
void construct_sa(string S,int *sa)
{
    n=S.length();
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
void construct_lcp(string S,int *sa,int *lcp)
{
    int n=S.length();
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
    scanf("%d",&t);
    string str;
    while(t--)
    {
        cin>>str;
        construct_sa(str,sa);
        construct_lcp(str,sa,lcp);
        int ans=n*(n+1)/2;
        for(int i=0;i<n;i++)
            ans-=lcp[i];
        printf("%d\n",ans);
    }
    return 0;
}
