#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define MAXN 800005
#define INF 1000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int n,k,a[MAXN];
int type[MAXN],x[MAXN];
ll dsum[MAXN];
int p2[MAXN],zero;
ll tp2[MAXN];
int ts,tt;
ll tot;
ll deq[MAXN];
int solve(int id,int cur,int rem)
{
    if(dsum[id]!=0&&tt-cur-1>30) return solve(id,tt-31,rem);  
    if(rem<=dsum[id]) return 1;
    if(dsum[id]==0&&zero>=tt-cur) return p2[tt-cur];
    if(cur>=tt) return 1;
    if(rem>tp2[tt-cur-1]*dsum[id]+deq[cur]) 
    {
        int res=p2[tt-cur-1];
        add(res,solve(id,cur+1,rem-tp2[tt-cur-1]*dsum[id]-deq[cur]));
        return res;
    }
    else return solve(id,cur+1,rem);
}
signed main()
{
    p2[0]=1;
    tp2[0]=1;
    for(int i=1;i<=800000;i++) p2[i]=2LL*p2[i-1]%MOD;
    for(int i=1;i<=31;i++) tp2[i]=2LL*tp2[i-1];
    scanf("%lld",&n);
    int cnt=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&type[i]);
        if(type[i]!=3) scanf("%lld",&x[i]);
        if(type[i]==2) cnt++;
    }
    if(!cnt)
    {
        int c=0,ans=0;
        for(int i=n;i>=1;i--)
        {
            if(type[i]==1) add(ans,p2[c]);
            else if(type[i]==3) c++;
        }
        printf("%lld\n",ans); return 0;
    }
    for(int i=1;i<=n;i++)
    {
        dsum[i]=dsum[i-1];
        if(type[i]==2) dsum[i]=min(INF,dsum[i]+x[i]);
        else if(type[i]==3) dsum[i]=min(INF,dsum[i]*2);
    }
    ts=tt=0; zero=0;
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        if(type[i]==3)
        {
            deq[tt++]=0; zero++;
        }
        else if(type[i]==2)
        {
            while(tt-1-ts>=31) ts++;  
            for(int j=ts;j<tt;j++) 
            {
                deq[j]+=1LL*x[i]*tp2[tt-j-1];
                if(deq[j]>INF) deq[j]=INF;
            }
            tot+=x[i];
            while(ts<tt&&deq[ts]>=INF) ts++;
            zero=0;
        }
        else if(x[i]>tot) 
        {
            add(ans,solve(i,ts,x[i]-tot));
        }
    }
    printf("%lld\n",ans);
    return 0;
}

