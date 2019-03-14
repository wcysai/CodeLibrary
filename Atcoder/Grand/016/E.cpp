#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 405
#define MAXM 100005
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
int n,m;
int x[MAXM],y[MAXM];
bitset<400> bs[MAXN];
bool valid[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {scanf("%d%d",&x[i],&y[i]); x[i]--;y[i]--;}
    memset(valid,true,sizeof(valid));
    for(int i=0;i<n;i++)
    {
        bs[i].set(i);
        for(int j=m-1;j>=0;j--)
        {
            if(bs[i][x[j]]&&bs[i][y[j]])
            {
                valid[i]=false;
                break;
            }
            else if(bs[i][x[j]]) bs[i][y[j]]=true;
            else if(bs[i][y[j]]) bs[i][x[j]]=true;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(valid[i]&&valid[j]&&!((bs[i]&bs[j]).count())) ans++;
    printf("%d\n",ans);
    return 0;
}

