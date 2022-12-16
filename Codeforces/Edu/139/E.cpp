#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int r1[MAXN],r2[MAXN],r3[MAXN],nxt[MAXN];
int r321[MAXN],r312[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll ans=0;
    int zeroes=0;
    for(int i=1;i<=n;i++)
    {
        if(!a[i]) {ans+=1LL*i*(n-i+1); zeroes++;}
        else {ans+=1LL*(zeroes+1)*(n-i+1); zeroes=0;}
    }
    r1[n+1]=r2[n+1]=r3[n+1]=nxt[n+1]=r321[n+1]=r312[n+1]=n+1; 
    for(int i=n;i>=1;i--)
    {
        r1[i]=r1[i+1]; r2[i]=r2[i+1]; r3[i]=r3[i+1];
        if(a[i]==1) r1[i]=i;
        else if(a[i]==2) r2[i]=i;
        else if(a[i]==3) r3[i]=i;
        if(a[i+1]) nxt[i]=i+1; else nxt[i]=nxt[i+1];
        //printf("i=%d nxt=%d\n",i,nxt[i]);
    }
    for(int i=n;i>=1;i--)
    {
        r321[i]=r312[i]=n+1;
        if(a[i]==3)
        {
            if(a[nxt[i]]==2&&r1[nxt[i]]!=n+1&&r1[nxt[i]]<=r3[nxt[i]]) r321[i]=r1[nxt[i]];
            if(a[nxt[i]]==1&&r2[nxt[i]]!=n+1&&r2[nxt[i]]<=r3[nxt[i]]) r312[i]=r2[nxt[i]];
        }
        r321[i]=min(r321[i],r321[i+1]); r312[i]=min(r312[i],r312[i+1]);
    }
    int save=n+1;
    set<P> s;
    for(int i=n;i>=1;i--)
    {
        if(a[i]==1)
        {
            if(r2[i]<=n&&r2[i]<=r3[i]) s.insert(P(r2[i],1));
        }
        if(a[i]==2)
        {
            if(r1[i]<=n&&r1[i]<=r3[i]) s.insert(P(r1[i],2));
        }
        if(!s.size()) continue;
        auto p=*s.begin();
        ans+=n-p.F+1;
        if(p.S==1)//12 find 321
        {
            if(p.F!=n+1) 
            {
                //printf("i=%d nxt=%d\n",i,r321[p.F+1]);
                ans+=n+1-r321[p.F+1];
            }
        }
        else//21 find 312
        {
            if(p.F!=n+1) 
            {
                //printf("i=%d nxt=%d\n",i,r312[p.F+1]);
                ans+=n+1-r312[p.F+1];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

