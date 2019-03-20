#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
#define MAXM 20
#define MAXK (1<<MAXM)
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define prev daksiisaas
#define next aijdkjsaod
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int N,V,x[MAXN];
vector<int> v;
int prev[MAXN][MAXM],next[MAXN][MAXM];
int predp[MAXK],sufdp[MAXK];
int mini[MAXN];
int main()
{
    scanf("%d%d",&N,&V);
    for(int i=1;i<=N;i++) scanf("%d",&x[i]);
    int dummy=V;
    while(dummy)
    {
        v.push_back(dummy);
        dummy/=2;
    }
    v.push_back(0);
    reverse(v.begin(),v.end());
    int sz=(int)v.size();
    for(int i=(int)v.size()-1;i>=0;i--) next[N][i]=N;
    for(int i=N-1;i>=0;i--)
        for(int j=(int)v.size()-1;j>=0;j--)
            if(x[i+1]-x[i]>v[j]) next[i][j]=i; else next[i][j]=next[i+1][j];
    for(int i=(int)v.size()-1;i>=0;i--) prev[1][i]=1;
    for(int i=2;i<=N;i++)
        for(int j=(int)v.size()-1;j>=0;j--)
            if(x[i]-x[i-1]>v[j]) prev[i][j]=i; else prev[i][j]=prev[i-1][j];
    //for(int i=1;i<=N;i++) printf("%d %d %d %d\n",prev[i][1],prev[i][2],next[i][1],next[i][2]);
    memset(predp,0,sizeof(predp));
    for(int mask=0;mask<(1<<sz);mask++)
    {
        for(int j=0;j<sz;j++)
        {
            if(mask&(1<<j)) continue;
            predp[mask^(1<<j)]=max(predp[mask^(1<<j)],next[min(predp[mask]+1,N)][j]);
        }
    }
    for(int mask=0;mask<(1<<sz);mask++) sufdp[mask]=N+1;
    for(int mask=0;mask<(1<<sz);mask++)
    {
        for(int j=0;j<sz;j++)
        {
            if(mask&(1<<j)) continue;
            sufdp[mask^(1<<j)]=min(sufdp[mask^(1<<j)],prev[max(sufdp[mask]-1,1)][j]);
        }
    }
    for(int i=0;i<=N+1;i++) mini[i]=N+2; 
    for(int mask=0;mask<(1<<(sz-1));mask++)
    {
        int dmask=(1<<(sz-1))-1-mask;
        int l=predp[mask],r=sufdp[dmask];
        mini[l]=min(mini[l],r);
    }
    for(int i=N;i>=0;i--) mini[i]=min(mini[i],mini[i+1]);
    for(int i=1;i<=N;i++)
    {
        int l=prev[i][sz-1],r=next[i][sz-1];
        if(l==1&&r==N) {puts("Possible"); continue;}
        //printf("%d %d\n",l,r);
        if(mini[l-1]<=r+1) puts("Possible"); else puts("Impossible");
    }
    return 0;
}

