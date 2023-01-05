#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 600005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN],b[MAXN],x[MAXN];
int bit[MAXN];
int cnt[MAXM];
vector<int> upd[MAXM];
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}
vector<int> dis;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        dis.clear();
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            dis.push_back(a[i]);
        }
        for(int i=1;i<=n;i++) {
            scanf("%d",&b[i]);
            dis.push_back(b[i]);
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            scanf("%d",&x[i]);
            dis.push_back(x[i]);
        }
        bool f=true;
        for(int i=1;i<=n;i++) if(a[i]<b[i]) f=false; 
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=n;i++) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
        for(int i=1;i<=n;i++) b[i]=lower_bound(dis.begin(),dis.end(),b[i])-dis.begin()+1;
        for(int i=1;i<=m;i++) x[i]=lower_bound(dis.begin(),dis.end(),x[i])-dis.begin()+1;
        int sz=(int)dis.size();
        for(int i=1;i<=sz;i++) {cnt[i]=0; upd[i].clear();}
        for(int i=1;i<=m;i++) cnt[x[i]]++;
        for(int i=1;i<=n;i++) upd[b[i]].push_back(i);
        for(int i=1;i<=n;i++) bit[i]=0;
        for(int i=sz;i>=1;i--){
            int last=-1,c=0;
            for(auto x:upd[i]){
                if(a[x]!=b[x]){
                    int s=sum(x);
                    if(s!=last) c++;
                    last=s;
                }
            }
            for(auto x:upd[i]) add(x,1);
            if(cnt[i]<c) {f=false; break;}
        }
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

