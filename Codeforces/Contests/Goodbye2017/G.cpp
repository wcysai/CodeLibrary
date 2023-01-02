#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 705
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cur;
string str;
int p10[MAXN];
P dp[MAXN][MAXN][2][2];
//a: multiple of original cont
//b: new cont
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
P solve(int now,int cnt,int less,int zero){
    if(now==n) return P(1,0);
    if(dp[now][cnt][less][zero].F!=0) return dp[now][cnt][less][zero];
    int limit=(less?9:str[now]-'0');
    P res=P(0,0);
    for(int i=0;i<=limit;i++){
        P p=solve(now+1,i>=cur?cnt+1:cnt,less||(i<limit),(zero&&(!i))?1:0);
        add(res.S,p.S);
        if(i==cur){
            add(res.S,1LL*cur*p10[cnt]*p.F%MOD);
            add(res.F,p.F);
        }
        else if(i<cur){
            add(res.F,p.F%MOD);
        }
        else{
            add(res.F,10LL*p.F%MOD);
        }
    }
    return dp[now][cnt][less][zero]=res;
}
int calc(int d){
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<2;k++)
                for(int l=0;l<2;l++)
                    dp[i][j][k][l]=P(0,0);
    return solve(0,0,0,1).S;
}
int main()
{
    cin>>str;
    n=(int)str.size();
    p10[0]=1;
    for(int i=1;i<=700;i++) p10[i]=10LL*p10[i-1]%MOD;
    int ans=0;
    for(int i=1;i<=9;i++){
        cur=i;
        add(ans,calc(i));
    }
    printf("%d\n",ans);
    return 0;
}

