#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 41
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k;
int f[MAXN][MAXN][MAXN][MAXN][MAXN];
int inv[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
//f[i][j][k]:
//probability that at the ith round
//j people don't have a gift
//the k-th people who doesn't have a gift stil doesn't get one in this round
//and j2 people don't have a gift after this round
//and that people become the k2-th one
int solve(int i,int j,int k,int j2,int k2)
{
    if(dp[i][j][k][j2][k2]!=-1) return dp[i][j][k][j2][k2];
    int has=n-j;
    assert(i-1>=has);
    int prob_hit=1LL*(k-has)/(k-(i-1));
    prob_fail=1; dec(prob_fail,prob_hit);
    if(k==1) 
    {
        int sum=0;
        int prob=1;
        for(int it=2;it<=j;it++) 
        {
            prob=1LL*prob*prob_fail%MOD;
            add(sum,1LL*prob*prob)
        }
    }
    int res=0;
    add(res,1LL*prob_fail*solve(i,j,k-1,))
}
int main()
{
    scanf("%d%d",&n,&k);
    return 0;
}

