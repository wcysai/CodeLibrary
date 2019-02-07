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
int n,m,g;
string s,t;
int main()
{
    scanf("%d%d",&n,&m);
    int g=__gcd(n,m);
    cin>>s; cin>>t;
    bool f=true;
    for(int i=0;i<g;i++)
    {
        if(s[i*(n/g)]!=t[i*(m/g)])
        {
            f=false;
            break;
        }
    }
    if(!f) puts("-1"); else printf("%lld\n",1LL*n*m/g);
    return 0;
}

