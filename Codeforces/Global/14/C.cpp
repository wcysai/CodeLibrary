#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,x;
P h[MAXN];
set<P> s;
int y[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&x);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&h[i].F);
            h[i].S=i;
        }
        sort(h+1,h+n+1,greater<P>());
        s.clear(); for(int i=1;i<=m;i++) s.insert(P(0,i));
        for(int i=1;i<=n;i++)
        {
            auto it=s.begin();
            P p=*it;
            y[h[i].S]=it->S;
            s.erase(it);
            s.insert(P(p.F+h[i].F,p.S));
        }
        if((--s.end())->F-s.begin()->F>x) puts("-1");
        else {for(int i=1;i<=n;i++) printf("%d%c",y[i],i==n?'\n':' ');}
    }
    return 0;
}