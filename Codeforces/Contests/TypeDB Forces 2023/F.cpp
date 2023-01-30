#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
bool vis[MAXN];
int ccnt[MAXN];
map<int,int> mp;
int ans[MAXN];
vector<vector<int> > cycs[MAXN];
int num[MAXN];
int pow_mod(int a,int i,int m){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%m;
        a=1LL*a*a%m;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        mp.clear();
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) vis[i]=false;
        for(int i=1;i<=n;i++) cycs[i].clear();
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                vector<int> tmp;
                int cnt=0,now=i;
                while(!vis[now]){
                    cnt++; vis[now]=true;
                    tmp.push_back(now);
                    now=a[now];
                }
                mp[cnt]++;
                cycs[cnt].push_back(tmp);
            }
        }
        vector<P> v;
        for(auto p:mp) v.push_back(p);
        sort(v.begin(),v.end(),greater<P>());
        bool f=true;
        for(int i=0;i<(int)v.size();i++){
            if(v[i].F%2==0){
                int cur=v[i].F,need=1;
                for(int j=1;j<=k;j++){
                    cur*=2; need*=2;
                    if(cur>n) break;
                }
                if(cur>n||v[i].S%need) {f=false; break;}
            }
        }
        if(!f) {puts("NO"); continue;}
        puts("YES");
        for(int i=1;i<=n;i+=2){
            if(cycs[i].size())
            {
                int ssz=(int)cycs[i].size(),cur=ssz;
                for(int z=min(k,18);z>=0;z--)
                {
                    while(cur>=(1<<z))
                    {
                        int st=pow_mod(2,k-z,i);
                        for(int y=cur-1;y>=cur-(1<<z);y--){
                            vector<int> tmp;
                            tmp.resize(i);
                            int now=0;
                            for(int j=0;j<i;j++) 
                            {
                                tmp[now]=cycs[i][y][j];
                                now=(now+st)%i;
                            }
                            for(int j=0;j<i;j++) cycs[i][y][j]=tmp[j];
                        }
                        cur-=(1<<z);
                    }
                }
            }
        }
        for(int i=1;i<=k;i++){
            bool upd=false;
            for(int j=n;j>=1;j--){
                vector<vector<int> > vv;
                while(cycs[j].size()>=2){
                    upd=true;
                    auto x=cycs[j].back(); cycs[j].pop_back();
                    auto y=cycs[j].back(); cycs[j].pop_back();
                    vector<int> tmp;
                    for(int i=0;i<(int)x.size();i++) {tmp.push_back(x[i]); tmp.push_back(y[i]);}
                    vv.push_back(tmp);
                }
                if(vv.size()){
                    for(int z=vv.size()-1;z>=0;z--) cycs[2*j].push_back(vv[z]);
                }
            }
            if(!upd) break;
        }
        for(int i=1;i<=n;i++){
            for(auto x:cycs[i])
                for(int j=0;j<(int)x.size();j++)
                    if(j==(int)x.size()-1) ans[x[j]]=x[0]; else ans[x[j]]=x[j+1];
        }
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}
