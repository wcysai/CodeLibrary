#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,sz;
vector<int> l,r;
int dp[20][2][2][2][10][10];
int nxt[20][2][2][2][10][10];
int solve(int now,int smaller,int larger,int zero,int least,int greatest){
    int &res=dp[now][smaller][larger][zero][least][greatest];
    if(res!=-1){
        return res;
    }
    if(now==sz){
        int ans=greatest-least;
        return res=ans;
    }
    int lb=(larger?0:l[now]);
    int rb=(smaller?9:r[now]);
    res=10;
    for(int i=lb;i<=rb;i++){
        int nl=least,ngr=greatest;
        if((!zero)||(i>0)){
            nl=min(nl,i); ngr=max(ngr,i);
        }
        int nres=solve(now+1,smaller||(i<rb),larger||(i>lb),zero&&(i==0),nl,ngr);
        if(nres<res){
            res=nres;
            nxt[now][smaller][larger][zero][least][greatest]=i;
        }
    }
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        l.clear(); r.clear();
        ll x,y;
        scanf("%lld%lld",&x,&y);
        while(x) {l.push_back(x%10); x/=10;}
        while(y) {r.push_back(y%10); y/=10;}
        while(l.size()<r.size()) l.push_back(0);
        reverse(l.begin(),l.end());
        reverse(r.begin(),r.end());
        sz=(int)r.size();
        solve(0,0,0,1,9,0);
        ll ans=0;
        int now=0,smaller=0,larger=0,zero=1,least=9,greatest=0;
        while(now<sz){
            int d=nxt[now][smaller][larger][zero][least][greatest];
            ans=ans*10+d;
            smaller=(smaller||(d<r[now]));
            larger=(larger||(d>l[now]));
            if((!zero)||(d>0)){
                least=min(least,d);
                greatest=max(greatest,d);
            }
            zero=(zero&&(d==0));
            now++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

