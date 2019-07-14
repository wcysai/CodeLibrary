#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<P> row[MAXN],col[MAXN];
vector<int> ed[MAXN];
int bit[MAXN+1];
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
    while(i<=MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a+=5000; b+=5000; c+=5000; d+=5000;
        if(a==c) col[a].push_back(P(min(b,d),max(b,d)));
        else row[b].push_back(P(min(a,c),max(a,c)));
    }
    ll ans=0;
    for(int i=0;i<=10000;i++)
    {
        for(auto p:row[i])
        {
            for(int j=p.F;j<=p.S;j++) 
            {
                for(auto q:col[j])
                {
                    if(q.F>i||q.S<i) continue;
                    ed[q.S+1].push_back(j);
                    add(j,1);
                }
            }
            for(int j=i+1;j<=10001;j++)
            {
                for(auto x:ed[j]) add(x,-1);
                for(auto q:row[j]) 
                {
                    int l=max(q.F,p.F);
                    int r=min(q.S,p.S);
                    if(l>r) continue;
                    int x=sum(r)-sum(l-1);
                    ans+=x*(x-1)/2;
                }
                ed[j].clear();
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

