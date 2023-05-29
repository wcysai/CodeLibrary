#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define F first
#define S second
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int T,n;
void add(ll &a,ll b) {a+=b; }
char str[MAXN];
int len[MAXN];
int mini[MAXN];
ll dp[MAXN];
void manacher(int n)
{
    len[0]=1;
    for(int i=1,j=0;i<(n<<1)-1;++i)
    {
        int p=i>>1,q=i-p,r=((j+1)>>1)+len[j]-1;
        len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
        while(p>len[i]-1&&q+len[i]<n&&str[p-len[i]]==str[q+len[i]])
            ++len[i];
        if(q+len[i]-1>r)
            j=i;
    }
}
vector<P> upd[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",str);
        manacher(n);
        for(int i=0;i<=n;i++) mini[i]=INF;
        int val=0;
        for(int i=0;i<=n;i++) upd[i].clear();
        for(int i=1;i<2*n+1;i+=2){
            int now=i/2;
            if(len[i]){
                //now+1: 2 now+2: 
                upd[now+1].push_back(P(-now,1));
                upd[now+len[i]+1].push_back(P(-now,-1));
            }
        }
        multiset<int> ms;
        for(int i=0;i<n;i++){
            for(auto p:upd[i]){
                if(p.S==1) ms.insert(p.F); else ms.erase(ms.find(p.F));
            }
            if(ms.size()) mini[i]=2*(i+*(ms.begin()));
        }
        //for(int i=0;i<n;i++) printf("%d %d\n",i,mini[i]);
        for(int i=0;i<=n;i++) dp[i]=0;
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(mini[i-1]!=INF) add(dp[i],1+dp[i-mini[i-1]]);
            add(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
