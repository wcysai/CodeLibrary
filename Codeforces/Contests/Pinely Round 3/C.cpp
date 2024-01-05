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
vector<int> l,r,c;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        l.clear(); r.clear(); c.clear();
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x); l.push_back(x);
        }
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x); r.push_back(x);
        }
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x); c.push_back(x);
        }
        sort(l.begin(),l.end()); sort(r.begin(),r.end()); sort(c.begin(),c.end());
        vector<int> len;
        priority_queue<int> pq;
        int now=0;
        for(int i=0;i<n;i++){
            while(now<n&&l[now]<r[i]) {pq.push(l[now]); now++;}
            int x=pq.top(); pq.pop();
            len.push_back(r[i]-x);
        }
        sort(len.begin(),len.end());
        ll ans=0;
        for(int i=0;i<n;i++) ans+=1LL*c[i]*len[n-1-i];
        printf("%lld\n",ans);
    }
    return 0;
}

