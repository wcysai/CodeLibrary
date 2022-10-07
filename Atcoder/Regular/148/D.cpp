#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
map<int,int> mp;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=2*n;i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]%m]++;
    }
    for(auto &p:mp) p.S=p.S&1;
    bool f=true;
    if(m%2==0)
    {
        int cnt=0;
        for(auto p:mp)
        {
            if(p.S)
            {
                if(mp[(p.F+m/2)%m])
                {
                    mp[p.F]=mp[(p.F+m/2)%m]=0;
                    cnt++;
                }
            }
        }
        if(cnt&1) f=false;
    }
    for(auto p:mp) if(p.S) f=false;
    if(f) puts("Bob"); else puts("Alice");
    return 0;
}

