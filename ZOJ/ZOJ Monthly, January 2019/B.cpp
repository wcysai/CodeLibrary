#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,K,Q;
vector<int> a[MAXN];
int bit2[MAXN];
ll bit1[MAXN],q[11],ans[11];
ll sum(int i,int x)
{
    ll s=0,y=i;
    while(i>0)
    {
        s+=1LL*bit2[i]*(x+y)-bit1[i];
        i-=i&-i;
    }
    return s;
}
void add1(int i,int x)
{
    while(i<=N)
    {
        bit1[i]+=x;
        i+=i&-i;
    }
}
void add2(int i)
{
    while(i<=N)
    {
        bit2[i]++;
        i+=i&-i;
    }
}
int bisearch1(ll v,int x)
{
    ll sum1=0,sum2=0;
    int pos=0;
    for(int i=MAXLOGN;i>=0;i--)
    {
        int to=pos+(1<<i);
        if(to<=N&&1LL*(x+to)*(sum2+bit2[to])-sum1-bit1[to]<v)
        {
            sum2+=bit2[to];sum1+=bit1[to];
            pos=to;
        }
    }
    return pos;
}
int bisearch2(ll v,int x)
{
    ll sum1=0,sum2=0;
    int pos=0;
    for(int i=MAXLOGN;i>=0;i--)
    {
        int to=pos+(1<<i);
        if(to<=N&&1LL*(x+to)*(sum2+bit2[to])-sum1-bit1[to]<=v)
        {
            sum2+=bit2[to];sum1+=bit1[to];
            pos=to;
        }
    }
    return pos;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&K);memset(bit1,0,sizeof(bit1)); memset(bit2,0,sizeof(bit2)); memset(ans,0,sizeof(ans));
        for(int i=1;i<=N;i++) a[i].clear();
        for(int i=0;i<K;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            a[x].push_back(y);
        }
        scanf("%d",&Q);
        for(int i=1;i<=Q;i++) scanf("%lld",&q[i]);
        for(int i=1;i<=N;i++)
        {
            for(auto x:a[i]) add1(x,x+i),add2(x);
            for(int j=1;j<=Q;j++) ans[j]+=bisearch2(q[j],i)-bisearch1(q[j],i);
        }
        for(int i=1;i<=Q;i++) printf("%lld%c",ans[i],i==Q?'\n':' ');
    }
    return 0;
}

