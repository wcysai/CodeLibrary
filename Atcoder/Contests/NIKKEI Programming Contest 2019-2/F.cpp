#include<bits/stdc++.h>
#define MAXN 1505
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
#define exit dskosad
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
char str[MAXN][MAXN];
vector<P> v;
int get()
{
    int cnt1=0,cnt2=0;
    for(auto p:v)
    {
        if(str[p.F][p.S]=='x') cnt1++;
        else if(str[p.F][p.S]=='o') cnt2++;
    }
    if(cnt1&&cnt2) return 0;
    else if(cnt1||cnt2) return 1;
    else return 2;
}
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
    scanf("%d",&n);
    n--;
    for(int i=1;i<=n;i++) scanf("%s",str[i]);
    int ans=1;
    if(n%2==0)
    {
        for(int i=1;i<=n/2;i++)
            for(int j=1;j<=i;j++)
            {
                v.clear();
                v.push_back(P(i,j));
                v.push_back(P(j,i));
                v.push_back(P(n-i,n-j));
                v.push_back(P(n-j,n-i));
                ans=1LL*ans*get()%MOD;
            }
        for(int i=n/2+1;i<=n;i++)
            for(int j=1;j<=n+1-i;j++)
            {
                v.clear();
                v.push_back(P(i,j));
                v.push_back(P(j,i));
                v.push_back(P(n-i,n-j));
                v.push_back(P(n-j,n-i));
                ans=1LL*ans*get()%MOD;
            }
    }
    else
    {
        v.clear();
        v.push_back(P(n/2+1,n/2+1));
        ans=1LL*ans*get()%MOD;
        for(int i=1;i<=n/2;i++)
            for(int j=1;j<=i;j++)
            {
                if(i==j||i+j==n+1) continue;
                v.clear();
                v.push_back(P(i,j));
                v.push_back(P(j,i));
                v.push_back(P(n-i,n-j));
                v.push_back(P(n-j,n-i));
                ans=1LL*ans*get()%MOD;
            }
        for(int i=n/2+1;i<=n;i++)
            for(int j=1;j<=n+1-i;j++)
            {
                if(i==j||i+j==n+1) continue;
                v.clear();
                v.push_back(P(i,j));
                v.push_back(P(j,i));
                v.push_back(P(n-i,n-j));
                v.push_back(P(n-j,n-i));
                ans=1LL*ans*get()%MOD;
            }
        for(int i=1;i<=n/2;i++)
        {
            int j=i;
            v.clear();
            v.push_back(P(i,j));
            v.push_back(P(n-i,n-j));
            ans=1LL*ans*get()%MOD;
        }
        for(int i=1;i<=n/2;i++)
        {
            int x=n+1-i,y=i;
            v.push_back(P(x,y));
            v.push_back(P(y,x));
            ans=1LL*ans*get()%MOD;
        }
    }
    printf("%d\n",ans);
}
