#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN],b[MAXN];
int cnt[MAXN];
vector<int> save[MAXN];
vector<int> choice[MAXN];
int prel[MAXN],prer[MAXN],sufl[MAXN],sufr[MAXN];
multiset<int> s;
vector<P> upd[MAXN];
bool check(int x,int y,int z){
    return x+y>z&&x+z>y&&y+z>x;
}
void set_bad(int l,int r){
    printf("l=%d r=%d\n",l,r);
    if(l>r) return;
    cnt[l]++; cnt[r+1]--;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++) cnt[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n+1;i++) {save[i].clear(); upd[i].clear();} 
        s.clear();
        sort(a+1,a+n+1); sort(b+1,b+n+1); b[n+1]=INF+1; a[n+1]=INF+1;
        //for(int i=1;i<=n;i++)
        //for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
        //for(int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
        int now=1;
        for(int i=1;i<=n;i++){
            while(now<=n&&a[now]<b[i]) now++;
            save[now].push_back(i);
            int l=max(b[i]-a[now],a[now]-b[i])+1,r=b[i]+a[now]-1;
            upd[1].push_back(P(i,1));
            if(now>1) {
                save[now-1].push_back(i); 
                int l1=b[i]-a[now-1]+1;
                int r1=b[i]+a[now]-1;
                if(l1>r||l>r1){
                    int lpos=lower_bound(a+1,a+n+2,l)-a; 
                    int rpos=upper_bound(a+1,a+n+2,r)-a; 
                    if(lpos<rpos) {upd[lpos].push_back(P(i,-1)); upd[rpos].push_back(P(i,1));}
                    lpos=lower_bound(a+1,a+n+2,l)-a; 
                    rpos=upper_bound(a+1,a+n+2,r)-a; 
                    if(lpos<rpos) {upd[lpos].push_back(P(i,-1)); upd[rpos].push_back(P(i,1));}
                }
                else{
                    l=min(l,l1);
                    r=max(r,r1);
                    int lpos=lower_bound(a+1,a+n+2,l)-a; 
                    int rpos=upper_bound(a+1,a+n+2,r)-a; 
                    if(lpos<rpos) {upd[lpos].push_back(P(i,-1)); upd[rpos].push_back(P(i,1));}
                }
            }
            else{
                int lpos=lower_bound(a+1,a+n+2,l)-a; 
                int rpos=upper_bound(a+1,a+n+2,r)-a; 
                if(lpos<rpos) {upd[lpos].push_back(P(i,-1)); upd[rpos].push_back(P(i,1));}
            }
        }
        bool f=false;
        for(int i=1;i<=n;i++){
            for(auto p:upd[i]) if(p.S==1) s.insert(p.F); else s.erase(s.find(p.F)); 
            int l=INF,r=-INF;
            if(i>1) {l=min(l,a[i]-a[i-1]); r=max(r,a[i]+a[i-1]);}
            if(i<n) {l=min(l,a[i+1]-a[i]); r=min(r,a[i]+a[i+1]);}
            bool flag=true;
            for(auto x:save[i]) if(b[x]<=l||b[x]>=r) {flag=false; break;}
            if(!flag) continue;
            int pos=upper_bound(b+1,b+n+2,l)-b-1;
            if(pos>=1&&(s.size()&&*s.begin()<=pos)) flag=false;
            pos=lower_bound(b+1,b+n+2,r)-b;
            if(pos<=n&&(s.size()&&*(--s.end())>=pos)) flag=false;
            if(flag) {f=true; break;}
        }
        if(f) puts("Alice"); else puts("Bob");
    }
    return 0;
}

