#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define MAXM 3005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m,a[MAXN],w[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int ans[MAXN];
int dp[MAXM][MAXM];
int precomp[3*MAXM];
int main()
{
    scanf("%d%d",&n,&m);
    int sum=0,sump=0,sumn=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        if(a[i]) add(sump,w[i]); else add(sumn,w[i]);
    }
    add(sum,sump); add(sum,sumn);
    int invp=pow_mod(sump,MOD-2),invn=pow_mod(sumn,MOD-2);
    for(int i=0;i<=2*m;i++) precomp[i]=(sum-m+i>=0?pow_mod(sum-m+i,MOD-2):0);
    dp[0][0]=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!dp[i][j]) continue;
            int curp=(sump+j)%MOD;
            int prob=1LL*curp*precomp[j-(i-j)+m]%MOD;
            add(dp[i+1][j+1],1LL*prob*dp[i][j]%MOD);
            add(dp[i+1][j],1LL*(1-prob+MOD)*dp[i][j]%MOD);
        }
    }
    int negw=sumn,posw=sump;
    for(int i=0;i<=m;i++)
    {
        add(posw,1LL*i*dp[m][i]%MOD);
        dec(negw,1LL*(m-i)*dp[m][i]%MOD);
    }
    for(int i=1;i<=n;i++) 
    {
        if(a[i]) ans[i]=1LL*w[i]*invp%MOD*posw%MOD;
        else ans[i]=1LL*w[i]*invn%MOD*negw%MOD;
        printf("%d\n",ans[i]);
    }
    return 0;
}

