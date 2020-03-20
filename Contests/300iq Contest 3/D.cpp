#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,ans;
int inv[MAXN];
int s[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
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
vector<int> v;
int calc()
{
    int res=1;
    for(int j=2;j<=n;j++) res=1LL*res*j%MOD; 
    for(int i=1;i<=n;i++) s[i]=0;
    for(int i=0;i<(int)v.size();i++) s[v[i]]++;
    for(int i=1;i<=n;i++) s[i]+=s[i-1];
    for(int i=0;i<(int)v.size();i++)
    {
        for(int j=1;j<=v[i];j++)
        {
            int x=v[i]-j+1;
            x+=((int)v.size()-i-1)-s[j-1];
            res=1LL*res*inv[x]%MOD;
        }   
    }
    return 1LL*res*res%MOD;
}
void solve(int now,int left)
{
    if(left==0)
    {
        add(ans,calc());
        return;
    }
    for(int j=1;j<=min(now,left);j++)
    {
        v.push_back(j);
        solve(j,left-j);
        v.pop_back();
    }
}
int main()
{
    for(int i=1;i<=75;i++) inv[i]=pow_mod(i,MOD-2);
    scanf("%d",&n);
    for(int i=1;i<=n/2;i++)
    {
        v.clear();
        v.push_back(i); v.push_back(i);
        solve(i,n-2*i);
    }
    printf("%d\n",ans);
}