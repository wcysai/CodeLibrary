#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<ll> ans;
ll a[MAXN];
bool used[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    memset(used,false,sizeof(used));
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        int id=-1;
        for(int j=1;j<=n;j++)
        {
            ll cur=0;
            if(used[j]) continue;
            if(i==n) {id=j; break;}
            for(int k=1;k<=n;k++)
            {
                if(k==j||used[k]) continue;
                ll g=__gcd(a[j],a[k]);
                if(cur==0) cur=g;
                else
                {
                    ll gg=__gcd(cur,g);
                    cur=cur/gg*g;
                }
            }
            if(cur!=a[j])
            {
                id=j;
                break;
            }
        }
        if(id==-1) {flag=false; break;}
        else {ans.push_back(a[id]); used[id]=true;}
    }
    if(!flag) puts("No");
    else
    {
        puts("Yes");
        reverse(ans.begin(),ans.end());
        for(auto x:ans) printf("%lld ",x);
        puts("");
    }
    return 0;
}