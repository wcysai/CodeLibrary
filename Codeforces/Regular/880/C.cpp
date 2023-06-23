#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,k;
ll a[MAXN];
mt19937 wcy(time(NULL));
unordered_set<ll> s;
void solve(int x,int y){
    if(y>x+1){
        printf("%d %d %d %d\n",x+1,x+1,x+2,y);
    }
    else if(y<x-1){
        printf("%d %d %d %d\n",y+1,y+1,y+2,x);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        int n=(1<<(k+1));
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        vector<int> zero;
        for(int i=1;i<=n;i++) if(a[i]==0) zero.push_back(i);
        for(int i=1;i<=n;i++) a[i]^=a[i-1];
        if(zero.size()>=2){
            printf("%d %d %d %d\n",zero[0],zero[0],zero[1],zero[1]);
            continue;
        }
        s.clear();
        for(int i=0;i<=n;i++) s.insert(a[i]);
        int tot=0;
        while(true){
            tot++;
            int x=wcy()%(n+1);
            int y=wcy()%(n+1); while(y==x) y=wcy()%(n+1);
            if(a[x]==a[y]){
                if(max(x-y,y-x)>1) {solve(x,y); goto done;}
                else continue;
            }
            if(x>y) swap(x,y);
            ll res=a[y]^a[x];
            for(int i=0;i<=n-1;i++){
                if(i==x) continue;
                if(a[i]==a[x]){
                    if(max(x-i,i-x)>1) {solve(i,x); goto done;}
                    else continue;
                }
                if(a[i]==a[y]){
                    if(max(y-i,i-y)>1) {solve(i,y); goto done;}
                    else continue;
                }
                if(s.count(a[x]^a[y]^a[i])){
                    int z=-1;
                    for(int j=0;j<=n;j++) if(a[j]==(a[x]^a[y]^a[i])) {z=j; break;}
                    vector<int> v;
                    v.push_back(x); v.push_back(y); v.push_back(i); v.push_back(z);
                    sort(v.begin(),v.end());
                    printf("%d %d %d %d\n",v[0]+1,v[1],v[2]+1,v[3]);
                    goto done;
                }
            }
        }
done:;
    }
    return 0;
}

