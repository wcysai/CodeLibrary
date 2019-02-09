#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,num;
vector<ll> v;
ll mat[MAXN][MAXN];
int prime[10005],now;
bool is_prime[10005];
int sieve(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
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
ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b; 
}
void fill_diag_left(int x,int y)
{
    while(x<=n&&y<=n)
    {
        mat[x][y]*=prime[now];
        x++;y++;
    }
    now++;
}
void fill_diag_right(int x,int y)
{
    while(x<=n&&y>=1)
    {
        mat[x][y]*=prime[now];
        x++;y--;
    }
    now++;
}
void fill()
{
    for(ll i=1;i<=n;i++)
        for(ll j=2-(i&1);j<=n;j+=2)
            mat[i][j]=1;
    now=0;
    for(int i=1;i<=n;i+=2) fill_diag_left(1,i);
    for(int i=3;i<=n;i+=2) fill_diag_left(i,1);
    for(int i=1;i<=n;i+=2) fill_diag_right(1,i);
    for(int i=n;i>=2;i-=2) fill_diag_right(i,n);
}
bool check()
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(!mat[i][j])
            {
                ll g=1;
                if(i>1) g=lcm(g,mat[i-1][j]);
                if(j>1) g=lcm(g,mat[i][j-1]);
                if(i<n) g=lcm(g,mat[i+1][j]);
                if(j<n) g=lcm(g,mat[i][j+1]);
                mat[i][j]=g+1;
            }
        }
    }
    return true;
}
void print()
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
            printf("%lld ",mat[i][j]);
        puts("");
    }
}
int main()
{
    sieve(10000);
    scanf("%lld",&n);
    if(n==2)
    {
        puts("4 7\n23 10");
        return 0;
    }
    fill();
    assert(check());
    print();
    return 0;
}

