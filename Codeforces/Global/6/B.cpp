#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
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
ll x;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld",&x);
        if(x<21)
        {
            if(x<15) puts("NO"); else puts("YES");
            continue; 
        }
        int dice=(x-21)%14;
        if(14-dice>0&&14-dice<=6) puts("YES"); else puts("NO");
    }
    return 0;
}