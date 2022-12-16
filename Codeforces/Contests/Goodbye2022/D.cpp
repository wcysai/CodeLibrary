#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
bool is_prime[MAXN];
ll a[MAXN];
vector<int> p;
const int magic=100;//should be enough...
bool forbid[MAXN];
bool check(int pr)
{
    for(int i=0;i<pr;i++) forbid[i]=false;
    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            ll x=a[j]-a[i];
            if(x%pr) continue;
            if(!forbid[a[i]%pr]) cnt++;
            forbid[a[i]%pr]=true;
        }
    if(cnt==pr) return false; else return true;
}
int main()
{
    for(int i=2;i<=1000;i++) is_prime[i]=true;
    for(int i=2;i<=1000;i++)
    {
        if(is_prime[i]) p.push_back(i);
        for(int j=2*i;j<=1000;j+=i)
            is_prime[j]=false;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        set<ll> s;
        for(int i=1;i<=n;i++) 
        {
            scanf("%lld",&a[i]);
            s.insert(a[i]);
        }
        if(s.size()<n) {puts("NO"); continue;}
        sort(a+1,a+n+1);
        bool f=true;
        for(auto x:p) if(!check(x)) f=false;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

