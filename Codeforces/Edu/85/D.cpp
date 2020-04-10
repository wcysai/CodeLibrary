#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t,a[MAXN];
ll l,r;
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
vector<int> ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans.clear();
        scanf("%d%lld%lld",&n,&l,&r);
        bool f=false;
        if(r==1LL*n*(n-1)+1) f=true;
        ll now=1;
        while(now<n)
        {
            ll need=2*(n-now);
            if(need<l)
            {
                now++; l-=need; r-=need;
            }
            else
            {
                int tot=now;
                for(int i=1;i<=need;i++)
                {
                    if(i%2==0) ++tot;
                    if(l<=i&&i<=r) 
                    {
                        if(i&1) ans.push_back(now);
                        else ans.push_back(tot);
                    }
                }
                l=max(l,need+1);
                if(l<=r) {now++; l-=need; r-=need;}
            }
        }
        if(f) ans.push_back(1);
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}