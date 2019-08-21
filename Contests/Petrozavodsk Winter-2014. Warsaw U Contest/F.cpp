#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,l,w;
struct update
{
    int y,mult;
};
struct query
{
    int y,id,mult;
};
int bit[MAXN],n;
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=1000000)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
vector<update> t[MAXN];
vector<query> tq[MAXN];
int main()
{
    scanf("%d%d%d%d",&n,&q,&l,&w);
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        t[a].push_back((update){d,1});
        t[a].push_back((update){b,-1});
        t[c].push_back((update){d,-1});
        t[c].push_back((update){b,1});
    }
    for(int i=0;i<q;i++)
    {
        int a,b,c,d;
        scanf("%d%d",&a,&b);
        c=a+l; d=b+w;
        tq[c].push_back((query){d,i,1});
        tq[c].push_back((query){b,i,-1});
        tq[a].push_back((query){d,i,-1});
        tq[a].push_back((query){b,i,1});
    }
    ll sum=0;
    for(int i=1;i<=1000000;i++)
    {
        for(auto upd:t[i]) add(t[i].F,t[i].S);
        sum+=
    }
    return 0;
}
