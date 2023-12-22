#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int t,n,m,k;
int cnt[MAXN],l[MAXN],r[MAXN];
map<P,int> mp;
vector<P> events[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n+1;i++) events[i].clear();
        for(int i=1;i<=m;i++){
            scanf("%d%d",&l[i],&r[i]);
            events[l[i]].push_back(P(i,1));
            events[r[i]+1].push_back(P(i,-1));
        }
        for(int i=1;i<=m;i++) cnt[i]=0;
        mp.clear();
        set<int> s;
        int num=0,ans=0;
        for(int i=1;i<=n;i++){
            for(auto p:events[i]){
                if(p.S==1) s.insert(p.F);
                else s.erase(p.F);
            }
            if(s.size()==0) num++;
            else if(s.size()==1) cnt[*s.begin()]++;
            else if(s.size()==2){
                auto it=s.begin(); int x=*it;
                it++; int y=*it;
                mp[P(x,y)]++;
            }
        }
        vector<int> v;
        for(int i=1;i<=m;i++) v.push_back(cnt[i]);
        sort(v.begin(),v.end(),greater<int>());
        ans=max(ans,num+v[0]+v[1]);
        for(auto p:mp) ans=max(ans,num+cnt[p.F.F]+cnt[p.F.S]+p.S);
        printf("%d\n",ans);
    }
    return 0;
}
