#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<pair<int,int>,int> P;
int n;
set<P> V;
set<pair<P,P> > E;
void add_edge(P u,P v)
{
    if(u.F.F>v.F.F||(u.F.F==v.F.F&&u.F.S>v.F.S)||(u.F.F==v.F.F&&u.F.S==v.F.S&&u.S>v.S)) swap(u,v);
    E.insert(make_pair(u,v));
}
int main()
{
    freopen("genus.in","r",stdin);
    freopen("genus.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        P x,y,z;
        scanf("%d%d%d",&x.F.F,&x.F.S,&x.S);
        scanf("%d%d%d",&y.F.F,&y.F.S,&y.S);
        scanf("%d%d%d",&z.F.F,&z.F.S,&z.S);
        V.insert(x); V.insert(y); V.insert(z);
        add_edge(x,y); add_edge(y,z); add_edge(x,z);
    }
    printf("%d\n",(2-(n+(int)V.size()-(int)E.size()))/2);
    return 0;
}
