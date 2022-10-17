#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define INV 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p[MAXN];
bool vis[MAXN];
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
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    vector<int> v;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            int cnt=0,now=i;
            while(!vis[now])
            {
                cnt++;
                vis[now]=true;
                now=p[now];
            }
            v.push_back(cnt);
        }
    }
    int ans=0,sum=n,cur=1;
    for(int i=0;i<(int)v.size();i++)
    {
        int x=v[i];
        int ways=pow_mod(m,v[i]);
        dec(ways,m);
        ways=1LL*ways*INV%MOD;
        add(ans,1LL*cur*ways%MOD*pow_mod(m,sum-v[i])%MOD);
        sum-=v[i];
        cur=1LL*cur*m%MOD;
    }
    printf("%d\n",ans);
    return 0;
}

