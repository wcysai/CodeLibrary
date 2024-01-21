#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int last[MAXN];
vector<int> col[MAXN];
int cnt[MAXN],ans[MAXN];
vector<int> dis;
vector<P> pos;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); dis.push_back(a[i]);}
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=1;i<=n;i++) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin();
    for(int i=1;i<=n;i++){
        if(!cnt[a[i]]) {
            pos.push_back(P(a[i],1));
            cnt[a[i]]++;
        }
        else{
            int s=0;
            while(pos.back().F!=a[i]) {
                s+=pos.back().S;
                cnt[pos.back().F]-=pos.back().S;
                pos.pop_back();
            }
            pos.back().S+=s+1;
            cnt[a[i]]+=s+1;
        }
    }
    for(auto p:pos){
        for(int i=0;i<(int)p.S;i++) printf("%d\n",dis[p.F]);
    }
    return 0;
}

