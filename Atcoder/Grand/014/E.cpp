#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> PP;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n;
map<int,int> mp[MAXN];
set<PP> s;
map<P,int> cnt;
int find(int u,P p)
{
    if(u==p.F) return p.S;
    return p.F;
}
P get(int u,int v)
{
    if(u>v) swap(u,v);
    return  P(u,v);
}
void merge(int x,int y)
{
    if(mp[x].size()<mp[y].size()) swap(x,y);
    for(auto it:mp[y])
    {
        int z=it.F; int num=it.S;
        mp[y][z]-=num; mp[z][y]-=num;
        if(!num) continue;
        P e=get(y,z);
        s.erase(PP(num,e));
        e=get(x,z);
        if(mp[x][z]) s.erase(PP(mp[x][z],e));
        mp[x][z]+=num; mp[z][x]+=num; s.insert(PP(mp[x][z],e));
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*(n-1);i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u>v) swap(u,v);
        mp[u][v]++; mp[v][u]++;
        cnt[P(u,v)]++;
    }
    for(auto p:cnt) s.insert(PP(p.S,p.F));
    for(int i=0;i<n-1;i++)
    {
        auto it=s.end(); it--;
        if(s.size()<=0||(*it).F!=2)
        {
            puts("NO");
            return 0;
        }
        P p=(*it).S;
        int u=p.F,v=p.S;
        s.erase(it); 
        mp[u][v]-=2; mp[v][u]-=2;
        merge(u,v);
    }
    puts("YES");
    return 0;
}

