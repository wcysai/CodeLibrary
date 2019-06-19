#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<int> v;
int prime[MAXN];
bool is_prime[MAXN];
int p,cnt[MAXN],used[MAXN],st[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int n,k,neg;
vector<int> factors;
vector<vector<int> > ans;
void solve()
{
    vector<int> tmp=factors;
    sort(tmp.begin(),tmp.end());
    ans.push_back(tmp);
}
bool cmp(vector<int> &a,vector<int> &b)
{
    for(int i=0;i<(int)factors.size();i++) if(a[i]!=b[i]) return a[i]<b[i];
    return false;
}
void dfs(int cur,int parity)
{
    if(cur==p)
    {
        if(parity==neg) solve();
        return;
    }
    dfs(cur+1,parity);
    for(int i=1;i<=cnt[cur];i++)
    {
        parity^=1;
        factors[st[cur]+i-1]*=-1;
        dfs(cur+1,parity);
    }
    for(int i=1;i<=cnt[cur];i++) factors[st[cur]+i-1]*=-1;
}
int main()
{
    freopen("product.in","r",stdin);
    freopen("product.out","w",stdout);
    p=sieve(100000);
    scanf("%d",&n);
    if(n<0) neg=1,n=-n;
    for(int i=0;i<p;i++)
    {
        while(n%prime[i]==0) {factors.push_back(prime[i]); cnt[i]++; n/=prime[i];}
    }
    if(n!=1) factors.push_back(n);
    for(int i=1;i<p;i++) st[i]=st[i-1]+cnt[i-1];
    dfs(0,0);
    sort(ans.begin(),ans.end(),cmp);
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++)
    {
        for(auto x:ans[i]) printf("%d ",x);
        puts("");
    }
    return 0;
}
