#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m,a[MAXN][MAXN];
int cur[MAXN],cnt[MAXN];
bool del[MAXN];
bool ok()
{
    for(int i=1;i<=n;i++) if(cur[i]>m) return false;
    return true;
}
void calc()
{
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++) cnt[a[i][cur[i]]]++;
}
void dele(int x)
{
    del[x]=true;
    for(int i=1;i<=n;i++)
    {
        while(cur[i]<=m&&del[a[i][cur[i]]]) cur[i]++;
    }
}
bool check(int x)
{
    for(int i=1;i<=n;i++) cur[i]=1;
    memset(del,false,sizeof(del));
    while(true)
    {
        if(!ok()) return false;
        calc();
        bool done=true;
        for(int i=1;i<=m;i++)
        {
            if(cnt[i]>x) 
            {
                dele(i);
                done=false;
            }
        }
        if(done) return true;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    int l=0,r=n;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) r=mid; else l=mid;
    }
    printf("%d\n",r);
    return 0;
}

