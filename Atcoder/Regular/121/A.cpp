#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> PP;
int n;
PP p[MAXN];
vector<pair<int,P> > v;
int calc_dist(int x,int y)
{
    return max(max(p[x].F.F-p[y].F.F,p[y].F.F-p[x].F.F),max(p[x].F.S-p[y].F.S,p[y].F.S-p[x].F.S));
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        scanf("%d%d",&p[i].F.F,&p[i].F.S);
        p[i].S=i;
    }
    sort(p,p+n);
    v.push_back(make_pair(calc_dist(0,n-1),P(p[0].S,p[n-1].S)));
    v.push_back(make_pair(calc_dist(0,n-2),P(p[0].S,p[n-2].S)));
    v.push_back(make_pair(calc_dist(1,n-1),P(p[1].S,p[n-1].S)));
    for(int i=0;i<n;i++) swap(p[i].F.F,p[i].F.S);
    sort(p,p+n);
    v.push_back(make_pair(calc_dist(0,n-1),P(p[0].S,p[n-1].S)));
    v.push_back(make_pair(calc_dist(0,n-2),P(p[0].S,p[n-2].S)));
    v.push_back(make_pair(calc_dist(1,n-1),P(p[1].S,p[n-1].S)));
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    printf("%d\n",v[v.size()-2].F);
    return 0;
}