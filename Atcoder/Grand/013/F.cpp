#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,k,a[MAXN],b[MAXN],c[MAXN],d[MAXN],e[MAXN];
int val[MAXM],tmp[MAXM];
vector<int> dis;
vector<P> add[MAXM];
bool used[MAXN];
int need[MAXM];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);
        dis.push_back(a[i]); dis.push_back(b[i]); 
    }
    for(int i=1;i<=n+1;i++) {scanf("%d",&c[i]); dis.push_back(c[i]);}
    scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        scanf("%d%d",&d[i],&e[i]);
        dis.push_back(d[i]); dis.push_back(e[i]);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        b[i]=lower_bound(dis.begin(),dis.end(),b[i])-dis.begin()+1;
    }
    for(int i=1;i<=n+1;i++){
        c[i]=lower_bound(dis.begin(),dis.end(),c[i])-dis.begin()+1;
    }
    for(int i=1;i<=q;i++){
        d[i]=lower_bound(dis.begin(),dis.end(),d[i])-dis.begin()+1;
        e[i]=lower_bound(dis.begin(),dis.end(),e[i])-dis.begin()+1;
    }
    int sz=(int)dis.size();
    for(int i=1;i<=n;i++) val[a[i]]++;
    for(int i=1;i<=n+1;i++) val[c[i]]--;
    for(int i=1;i<=sz;i++) val[i]+=val[i-1];
    //for(int i=1;i<=sz;i++) printf("%d%c",val[i],i==sz?'\n':' ');
    for(int i=1;i<=n;i++){
        if(b[i]<a[i]){//add interval [b[i],a[i]-1]
            add[a[i]-1].push_back(P(b[i],i));
        }
    }
    int ans=0;
    set<P> s;
    bool f=true;
    int cur=0;
    //printf("sz=%d\n",sz);
    for(int i=sz;i>=1;i--){   
        cur+=tmp[i];
        int z=val[i]+cur;
        for(auto p:add[i]) s.insert(p);
        while(s.size()&&(--s.end())->F>i) s.erase(--s.end());
        int need=max(0,-1-z);
        //if(need) printf("i=%d need=%d\n",i,need);
        for(int i=0;i<need;i++){
            if(!s.size()){
                f=false;
                break;
            }
            P p=*s.begin();
            used[p.S]=true; ans++;
            cur++;
            tmp[b[p.S]-1]--; tmp[a[p.S]-1]++; 
            s.erase(s.begin());
        }
    }
    for(int i=sz;i>=1;i--) {tmp[i]+=tmp[i+1]; val[i]+=tmp[i];}
    //for(int i=1;i<=sz;i++) printf("%d%c",val[i],i==sz?'\n':' ');
    if(f){
        for(int i=1;i<=sz;i++) tmp[i]=0;
        cur=0;
        for(int i=1;i<=sz;i++) add[i].clear();
        for(int i=1;i<=n;i++)
            if(b[i]<a[i]&&!used[i])
                add[b[i]].push_back(P(a[i]-1,i));
        s.clear();
        for(int i=1;i<=sz;i++){
            cur+=tmp[i];
            for(auto p:add[i]) s.insert(p);
            while(s.size()&&s.begin()->F<i) s.erase(s.begin());
            int z=val[i]+cur;
            if(z==-1){
                if(!s.size()){
                    need[i+1]+=INF;
                    break;
                }
                else{
                    need[i+1]++;
                    P p=*(--s.end()); 
                    cur++; tmp[a[p.S]]--;
                    s.erase(--s.end());
                }
            }
        }
    }
    for(int i=1;i<=sz;i++) need[i]+=need[i-1];
    for(int i=1;i<=q;i++){
        if(!f) printf("-1\n");
        else{
            int res=min(ans+need[d[i]],ans+need[e[i]]+1);
            if(res>=INF) printf("-1\n"); else printf("%d\n",n+1-res);
        }
    }
    return 0;
}

