#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> PP;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T,N,K,a[MAXN];
int sum[MAXN];
vector<PP> rg[MAXN];
int main()
{
    for(int i=1;i<=100000;i++)
    {
        int last;
        for(int j=1;j<=i;j=last+1)
        {
            last=i/(i/j);
            rg[i].push_back(make_pair(P(j,last),i/j));
        }
    }
    T=read();
    while(T--)
    {
        N=read();K=read();
        for(int i=1;i<=N;i++) a[i]=read();
        memset(sum,0,sizeof(sum));
        for(int i=N;i>=1;i--)
        {
            for(auto p:rg[a[i]])
            {
                if(i-p.F.F<0) break;
                int l=max(1,i-p.F.S+1),r=i-p.F.F+1;
                sum[l]+=p.S;sum[r+1]-=p.S;
            }
        }
        for(int i=1;i<=N;i++) sum[i]+=sum[i-1];
        int ans=N+1;
        for(int i=N;i>=1;i--) if(sum[i]<=K) ans=min(ans,i); 
        printf("%d\n",ans);
    }
    return 0;
}

