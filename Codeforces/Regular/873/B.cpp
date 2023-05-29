#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,t,n,k,a[MAXN];
int L[MAXN],wtL[MAXN],R[MAXN],wtR[MAXN];
int st[MAXN];
vector<int> dis;
vector<P> upd[MAXN];
vector<P> qry[MAXN];
ll bit[2][MAXN+1];
ll sum(int id,int i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[id][i];
        i-=i&-i;
    }
    return s;
}
void add(int id,int i,ll x)
{
    while(i<=n)
    {
        bit[id][i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n); dis.clear();
        for(int i=1;i<=n;i++) bit[0][i]=bit[1][i]=0;
        for(int i=0;i<=n+1;i++) {upd[i].clear(); qry[i].clear();}
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); dis.push_back(a[i]);}
        sort(dis.begin(),dis.end());
        for(int i=1;i<=n;i++) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        t=0;
	    for(int i=1;i<=n-1;i++)
	    {
            wtL[i]=1;
		    while(t>0&&a[st[t-1]]<=a[i]) {L[st[t-1]]=i-1; wtL[i]+=wtL[st[t-1]]; t--;}
		    st[t++]=i;
	    }
        for(int i=0;i<t;i++) L[st[i]]=n-1;
        for(int i=1;i<=n-1;i++){
            //printf("i=%d L=%d wtL=%d\n",i,L[i],wtL[i]);
            upd[i].push_back(P(i,1));
            upd[L[i]+1].push_back(P(i,-1));
        }
	    t=0;
	    for(int i=n;i>=2;i--)
	    {
            wtR[i]=1;
		    while(t>0&&a[st[t-1]]>=a[i]) {R[st[t-1]]=i;  wtR[i]+=wtR[st[t-1]]; t--;}
		    st[t++]=i;
	    }
        for(int i=0;i<t;i++) R[st[i]]=1;
        for(int i=2;i<=n;i++){
            //printf("i=%d R=%d wtR=%d\n",i,R[i],wtR[i]);
            qry[R[i]-1].push_back(P(i,-1));
            qry[i-1].push_back(P(i,1));
        }
        ll ans=0;
        for(int i=0;i<=n;i++){
            //printf("i=%d\n",i);
            for(auto p:upd[i]) {
                //printf("upd %d %d %d\n",p.F,p.S,wtL[p.F]);
                add(0,a[p.F],-1LL*p.S*wtL[p.F]*(i-1));
                add(1,a[p.F],1LL*p.S*wtL[p.F]);
            }
            for(auto p:qry[i]) 
            {
                //printf("qry %d %d %d\n",p.F,p.S,wtR[p.F]);
                ans+=1LL*p.S*sum(0,a[p.F])*wtR[p.F];
                ans+=1LL*p.S*sum(1,a[p.F])*wtR[p.F]*i;
                //printf("ans=%lld\n",ans);
            }
        }
        ll all=0;
        for(int i=1;i<=n-1;i++) all+=1LL*i*(n-i);
        printf("%lld\n",all-ans);
    }
    return 0;
}

