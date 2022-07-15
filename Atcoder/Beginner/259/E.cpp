#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
int n;
vector<P> v[MAXN];
map<int,P> maxi;
map<int,ull> hsh;
mt19937_64 wcy(time(NULL));
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=0;j<x;j++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[i].push_back(P(a,b));
            if(maxi.find(a)==maxi.end()) {maxi[a]=P(b,1); hsh[a]=wcy();}
            else if(maxi[a].F==b) maxi[a].S++;
            else if(maxi[a].F<b) maxi[a]=P(b,1);
        }
    }
    set<ull> s;
    for(int i=1;i<=n;i++)
    {
        ull h=0;
        for(auto p:v[i])
        {
            P q=maxi[p.F];
            if(q.F==p.S&&q.S==1) h^=hsh[p.F];
        }
        s.insert(h);
    }
    printf("%d\n",(int)s.size());
    return 0;
}

