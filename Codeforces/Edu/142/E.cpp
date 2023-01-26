#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int t,n,m1,m2,p,prime[MAXN],fact[MAXN],sz,lim;
bool is_prime[MAXN];
map<int,int> mp;
vector<P> v;
vector<int> pw;
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i; 
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
void factorize(int x){
    for(int i=0;i<p;i++){
        while(x%prime[i]==0){
            mp[prime[i]]++;
            x/=prime[i];
        }
        if(x==1) break;
    }
    if(x>1) mp[x]++;
}
vector<int> decode(int id){
    vector<int> ret; ret.resize(sz);
    for(int i=0;i<sz;i++){
        ret[i]=id/pw[i];
        id-=ret[i]*pw[i];
    }
    return ret;
}
int main()
{
    p=sieve(100000);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m1,&m2);
        if(m1==1&&m2==1){
            printf("%d %d\n",1,1);
            continue;
        }
        mp.clear();
        factorize(m1); factorize(m2);
        v.clear();
        lim=1;
        for(auto p:mp) {
            v.push_back(p);
            lim=lim*(p.S+1);
        }
        //for(auto p:v) printf("(%d %d)\n",p.F,p.S);
        sz=(int)v.size();
        pw.clear(); pw.resize(sz); pw[sz-1]=1;
        for(int i=sz-2;i>=0;i--)
            pw[i]=pw[i+1]*(v[i+1].S+1);
        vector<ll> dp(lim,0),val(lim,0);
        int ans1=0,ans2=0;
        for(int i=0;i<lim;i++){
            vector<int> vec=decode(i);
            if(i==0) val[i]=1;
            for(int j=0;j<sz;j++){
                if(vec[j]){
                    val[i]=val[i-pw[j]]*v[j].F;
                    break;
                }
            }
            dp[i]=(val[i]>n?0:1LL*val[i]*n);
            for(int j=0;j<sz;j++)
                if(vec[j]) dp[i]=max(dp[i],dp[i-pw[j]]);
            //printf("i=%d val=%d dp=%lld\n",i,val[i],dp[i]);
            if(dp[i]>=val[i]){
                ans1++; ans2^=val[i]/(dp[i]/n);
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}

