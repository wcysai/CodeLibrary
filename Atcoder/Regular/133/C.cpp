#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
ll s=0;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int sa=0,sb=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        sa=(sa+a[i])%k;
    }
    for(int i=1;i<=m;i++) 
    {
        scanf("%d",&b[i]);
        sb=(sb+b[i])%k;
    }
    if(sa!=sb) {puts("-1"); return 0;}
    s=1LL*(n-1)*(m-1)*(k-1);
    ll ss=0;
    for(int i=1;i<=n-1;i++)
    {
        c[i]=(a[i]-1LL*(m-1)*(k-1))%k;
        if(c[i]<0) c[i]+=k;
        s+=c[i]; ss+=c[i];  
    }
    ll ss2=0;
    for(int i=1;i<=m-1;i++)
    {
        d[i]=(b[i]-1LL*(n-1)*(k-1))%k;
        if(d[i]<0) d[i]+=k;
        s+=d[i]; ss2+=d[i];
    }
    int tmp=(b[m]-ss)%k; if(tmp<0) tmp+=k;
    s+=tmp; 
    ll rem=min(1LL*(n-1)*(k-1)-ss,1LL*(m-1)*(k-1)-ss2);
    s+=1LL*k*((rem+(k-1-tmp))/k);
    printf("%lld\n",s);
    return 0;
}