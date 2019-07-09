#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
string s,t,str;
int r[MAXN+1];
int sa[MAXN],lcp[MAXN];
int c[MAXN],t1[MAXN],t2[MAXN];
void construct_sa(string S,int *sa) 
{
    int n=S.length()+1;
    int m=130;
    int i,*x=t1,*y=t2;
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=S[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1) {
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
int pre[MAXN],suf[MAXN];
int main()
{
    freopen("hackers.in","r",stdin);
    freopen("hackers.out","w",stdout);
    cin>>s;
    cin>>t;
    str=s+'\0'+t;
    construct_sa(str,sa);
    construct_lcp(str,sa,lcp);
    int last=-1;
    for(int i=0;i<=(int)str.size();i++)
    {
        if(sa[i]>=(int)s.size()) last=(int)str.size()-sa[i]+1;
        else
        {
            if(i>0) last=min(last,lcp[i-1]);
            pre[sa[i]]=last;
        }
    }
    last=-1;
    for(int i=(int)str.size();i>=0;i--)
    {
        if(sa[i]>=(int)s.size()) last=(int)str.size()-sa[i]+1;
        else
        {
            if(i<=(int)str.size()) last=min(last,lcp[i]);
            suf[sa[i]]=last;
        }
    }
    for(int i=0;i<(int)s.size();i++) printf("%d ",max(pre[i],suf[i]));
    return 0;
}