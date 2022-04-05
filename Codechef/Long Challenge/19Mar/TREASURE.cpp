#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 31
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
int T,N,M,ans,cnt;
int a[MAXN][MAXN];
bitset<450> basis[450];
int res[450],tot;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void clear_basis()
{
    memset(res,-1,sizeof(res));
    for(int i=0;i<450;i++) basis[i].reset();
}
void add_basis(bitset<450> &bs,int v)
{
    for(int i=449;i>=0;i--)
    {
        if(!bs[i]) continue;
        if(res[i]==-1)
        {
            basis[i]=bs;
            res[i]=v;cnt++;
            return;
        }
        bs^=basis[i];v^=res[i];
    }
    if(v) ans=0;
}
int find_id(int x,int y)
{
    if((x+y)&1) 
    {
        if(x&1) return (x/2)*M+y/2-1;
        else return (x-1)/2*M+M/2+(y+1)/2-1;
    }
    else
    {
        if(x&1) return (x/2)*M+(y+1)/2-1;
        else return (x-1)/2*M+(M+1)/2+y/2-1;
    }
}
void set_bitset(bitset<450> &tmp,int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=1&&nx<=N&&ny>=1&&ny<=M) 
        {
            tmp.set(find_id(nx,ny));
        }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        tot=0;
        scanf("%d%d",&N,&M); 
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++)
                scanf("%d",&a[i][j]);
        cnt=0;
        clear_basis();
        ans=1;
        for(int i=1;i<=N;i++)
        {
            for(int j=(i&1?1:2);j<=M;j+=2)
            {
                if(a[i][j]!=-1)
                {
                    bitset<450> tmp;tmp.reset();
                    set_bitset(tmp,i,j);
                    add_basis(tmp,a[i][j]);
                }
            }
        }
        tot=0;
        clear_basis();
        for(int i=1;i<=N;i++)
        {
            for(int j=(i&1?2:1);j<=M;j+=2)
            {
                if(a[i][j]!=-1)
                {
                    bitset<450> tmp;
                    set_bitset(tmp,i,j);
                    add_basis(tmp,a[i][j]);
                }
            }
        }
        ans=1LL*pow_mod(2,N*M-cnt)*ans%MOD;
        printf("%d\n",ans);
    }
    return 0;
}

