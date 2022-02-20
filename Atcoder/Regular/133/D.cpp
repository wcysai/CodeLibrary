#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
ll L,R,V;
int dp[61][2][2][2][4];
//dp[now][uless][dless][mless][xmod]
ll curL,curR,curV;
int get_mod(int mod)
{
    if(mod==0||mod==1) return mod;
    else return (mod+1)%4;
}
int get_val(int mod)
{
    if(mod==1) return 1; else return 0;
}
int solve(int now,int uless,int dless,int mless,int xmod)
{
    if(now<0) return (mless?1:0);
    if(dp[now][uless][dless][mless][xmod]!=-1) return dp[now][uless][dless][mless][xmod];
    int cur=0;
    int vbit=((V>>now)&1);
    int Lbit=((curL>>now)&1);
    int Rbit=((curR>>now)&1);
    for(int lbit=0;lbit<=1;lbit++)
    {
        if(!dless&&(lbit<Lbit)) continue;
        if(now<=1&&lbit!=((xmod>>now)&1)) continue;
        for(int rbit=0;rbit<=1;rbit++)
        {
            if(!uless&&(rbit>Rbit)) continue;
            if(!mless&&(lbit>rbit)) continue;
            if((lbit^rbit)!=vbit) continue;
            add(cur,solve(now-1,uless||(rbit<Rbit),dless||(lbit>Lbit),mless||(lbit<rbit),xmod));
        } 
    }
    return dp[now][uless][dless][mless][xmod]=cur;
}
int main()
{
    scanf("%lld%lld%lld",&L,&R,&V);
    int ans=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            if((get_mod(i)^get_mod(j))!=V%4) continue;
            if((i==1||i==3)&&(j==1||j==3))
            {
                if(V!=(get_val(i)^get_val(j))) continue;
                ll now=L-1;
                while(now%4!=i) now++;
                now++;
                while(now%4!=j) now++;
                ll cnt=(R-now+4)/4;
                if(cnt<=0) continue;
                cnt%=MOD;
                add(ans,(1LL*cnt*(cnt+1)/2)%MOD);
            }
            else if((i==1||i==3))
            {
                ll res=V^get_val(i);
                if(j==2) res--;
                if(res>R||res<L) continue;
                ll now=L-1;
                while(now%4!=i) now++;
                ll cnt=(res-1-now+4)/4;
                if(cnt<=0) continue;
                cnt%=MOD;
                add(ans,cnt);
            }
            else if(j==1||j==3)
            {
                ll res=V^get_val(j);
                if(i==2) res--;
                if(res>=R||res<L-1) continue;
                ll now=res+1;
                while(now%4!=j) now++;
                ll cnt=(R-now+4)/4;
                if(cnt<=0) continue;
                cnt%=MOD;
                add(ans,cnt);
            }
            else
            {
                if(i==0) curL=L-1; else curL=L;
                if(j==0) curR=R; else curR=R+1;
                memset(dp,-1,sizeof(dp));
                add(ans,solve(60,0,0,0,i==0?0:3));
            }
            //printf("i=%d j=%d ans=%lld\n",i,j,ans);
        }
    printf("%d\n",ans);
    return 0;
}