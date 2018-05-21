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
#define MAXN 200005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,t;
ll r[MAXN+1];
ll sa[MAXN],lcp[MAXN];
string S,T;
ll c[MAXN],t1[MAXN],t2[MAXN];
void construct_sa(string S,ll *sa) 
{
    n=S.length()+1;
    ll m=130;
    ll i,*x=t1,*y=t2;
    for(i=0;i<m;i++) c[i]=0;
    for(i=0;i<n;i++) c[x[i]=S[i]]++;
    for(i=1;i<m;i++) c[i]+=c[i-1];
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
    for(ll k=1;k<=n;k<<=1) 
    {
        ll p=0;
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
void construct_lcp(string S,ll *sa,ll *lcp)
{
    ll n=S.length();
    for(ll i=0;i<=n;i++) r[sa[i]]=i;
    ll h=0;
    lcp[0]=0;
    for(ll i=0;i<n;i++)
    {
        ll j=sa[r[i]-1];
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
    while(scanf("%I64d",&t)==1)
    {
        if(t==0) break;
        cin>>S>>T;
        ll s1=S.length();
        S+='\0'+T;
        construct_sa(S,sa);
        construct_lcp(S,sa,lcp);
        n--;
        ll top=0,ans=0,cnt=0;
        P s[MAXN];
        for(ll i=2;i<n;i++)
        {
            if(lcp[i]<t) { top=0; cnt=0;}
            else
            {
                ll num=0;     
                if(sa[i]<s1) num++,cnt+=lcp[i]-t+1;
                while(top&&lcp[i]<=s[top].F)
                {
                    cnt-=s[top].S*(s[top].F-lcp[i]);    
                    num+=s[top--].S;                         
                }
                s[++top]=mp(lcp[i],num);
                if(sa[i+1]>s1) ans+=cnt;
            }
        }
        top=0,cnt=0;
        for(ll i=2;i<n;i++)
        {
            if(lcp[i]<t)  {top=0; cnt=0;}
            else
            {
                ll num=0;     
                if(sa[i]>s1) num++,cnt+=lcp[i]-t+1;
                while(top&&lcp[i]<=s[top].F)
                {
                    cnt-=s[top].S*(s[top].F-lcp[i]);    
                    num+=s[top--].S;                         
                }
                s[++top]=mp(lcp[i],num);
                if(sa[i+1]<s1) ans+=cnt;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
