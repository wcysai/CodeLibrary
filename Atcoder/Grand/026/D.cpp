#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,h[MAXN];
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
P solve(int l,int r)
{ 
    int minh=INF;
    for(int i=l;i<=r;i++) minh=min(minh,h[i]);
    int cnt=0;
    for(int i=l;i<=r;i++)
    {
        h[i]-=minh;
        if(!h[i]) cnt++;
    }
    int ans1=1,ans2=1;
    int lb=INF,rb=-INF;
    for(int i=l;i<=r;i++)
    {
        if(h[i]==0)
        {
            if(rb!=-INF)
            {
                P p=solve(lb,rb);
                ans1=1LL*ans1*p.F%MOD;
                ans2=1LL*ans2*(p.F+p.S)%MOD;
            }
            lb=INF;rb=-INF;
        }
        else
        {
            lb=min(lb,i);
            rb=max(rb,i);
        }
    }
    if(rb!=-INF)
    {
        P p=solve(lb,rb);
        ans1=1LL*ans1*p.F%MOD;
        ans2=1LL*ans2*(p.F+p.S)%MOD;
    }
    ans2=1LL*ans2*pow_mod(2,cnt)%MOD;
    int mult=pow_mod(2,minh);
    dec(ans2,2LL*ans1%MOD); ans1=1LL*ans1*mult%MOD; add(ans2,ans1);
    return P(ans1,ans2);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    printf("%d\n",solve(1,n).S);
    return 0;
}

