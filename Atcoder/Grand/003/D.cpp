#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXN];
bool is_prime[MAXN];
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
int n;
ll s[MAXN];
map<ll,int> cnt;
ll is_square(ll x)
{
    int tmp=(int)sqrt(x);
    for(int i=max(1,tmp-5);i<=tmp+5;i++) if(1LL*i*i==x) return i;
    return 0;
}
int main()
{
    int pr=sieve(2500);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ll x=1,y=1;
        bool flag=true;
        for(int j=0;j<pr;j++)
        {
            if(s[i]==1) break;
            int cnt=0;
            while(s[i]%prime[j]==0) s[i]/=prime[j],cnt++;
            cnt%=3;
            if(cnt==0) continue;
            else if(cnt==1) 
            {
                if(10000000000LL/y<prime[j]*prime[j])
                {
                    flag=false;
                    break;
                }
                x=1LL*x*prime[j],y=1LL*y*prime[j]*prime[j];
            }
            else x=1LL*x*prime[j]*prime[j],y=1LL*y*prime[j];
        }
        if(!flag)
        {
            ans++;
            continue;
        }
        if(s[i]>1)
        {
            ll tmp=is_square(s[i]);
            if(tmp) 
            {
                x=1LL*x*tmp*tmp; y=1LL*y*tmp;
            }
            else
            {
                if(s[i]>INF||10000000000LL/y<s[i]*s[i])
                {
                    ans++;
                    continue;
                }
                x=1LL*x*s[i]; y=1LL*y*s[i]*s[i];
            }
        }
        if(x==y)
        {
            if(cnt[x]==0) ans++;
            cnt[x]++; continue;
        }
        int a=cnt[x],b=cnt[y];
        ans-=max(a,b);
        a++; 
        ans+=max(a,b);
        cnt[x]++;
    }
    printf("%d\n",ans);
    return 0;
}
