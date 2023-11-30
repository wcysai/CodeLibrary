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
typedef pair<ll,int> PP;
int t,n,k,a[MAXN],h[MAXN];
vector<int> hero[MAXN];
ll res[MAXN];
vector<int> event[MAXN];
bool cmp(int x,int y){
    return h[x]>h[y];
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(res,0,sizeof(res));
        for(int i=1;i<=200000;i++) {hero[i].clear(); hero[i].shrink_to_fit();}
        for(int i=1;i<=n;i++){
            hero[a[i]].push_back(i);
        }
        for(int i=1;i<=200000;i++) {event[i].clear(); event[i].shrink_to_fit();}
        PP p1=P(0,0),p2=P(0,0);
        int sum=0;
        for(int i=1;i<=200000;i++){
            if(hero[i].size()){
                sort(hero[i].begin(),hero[i].end(),cmp);
                while(hero[i].size()>2) hero[i].pop_back();
                for(int j=1,r;j<=i-1;j=r+1){
                    r=(i-1)/((i-1)/j);
                    int x=(i-1)/j;
                    event[r].push_back(i);
                    sum++;
                }
                for(int k=0;k<(int)hero[i].size();k++){
                    PP p=PP(h[hero[i][k]],hero[i][k]);
                    if(p>p1){
                        if(p.S==p1.S) p1=p;
                        else{
                            p2=p1;
                            p1=p;
                        }
                    }
                    else if(p>p2&&p.S!=p1.S) p2=p;
                }
            }
        }
        if(p1.S) res[p1.S]=p1.F-p2.F;
        for(int r=200000;r>=1;r--){
            for(auto i:event[r]){
                int x=(i-1)/r;
                for(int k=0;k<(int)hero[i].size();k++){
                    PP p=PP(1LL*(x+1)*h[hero[i][k]],hero[i][k]);
                    if(p.F<=p2.F) continue;
                    if(p>p1){
                        if(p.S==p1.S) p1=p;
                        else{
                            p2=p1;
                            p1=p;
                        }
                    }
                    else if(p.S!=p1.S) p2=p;
                }
            }
            if(p1.S) res[p1.S]=max(res[p1.S],p1.F-p2.F);
        }
        for(int i=1;i<=n;i++) printf("%lld%c",res[i],i==n?'\n':' ');
    }
    return 0;
}

