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
#define MAXN 100005
using namespace std;
int n,k,t;
int r[MAXN+1];
int tmp[MAXN+1],len[MAXN],sa[MAXN],lcp[MAXN];
string S;
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
    while(t--)
    {
        cin>>S;
        S+=S;
        n=S.length();
        construct_sa(S,sa);
        construct_lcp(S,sa,lcp);
        int ans=0;
        bool f=true;
        for(int i=0;i<=n;i++)
        {
            if(sa[i]<n/2)
            {
                ans=sa[i];
                f=false;
                while(i<=n&&lcp[i]>=n/2)
                {
                    i++;
                    if(sa[i]<ans) ans=sa[i];
                }
            }
            if(!f) break;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
