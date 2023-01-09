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
vector<int> pos[MAXN];
int p[MAXN],q[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) pos[i].clear();
        bool f=true;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            pos[a[i]].push_back(i);
            if(pos[a[i]].size()>2) f=false;
        }
        if(!f) {puts("NO"); continue;}
        vector<int> v;
        for(int i=1;i<=n;i++){
            int num=(int)pos[i].size();
            if(num==1){
                int x=pos[i][0];
                p[x]=q[x]=i;
                continue;
            }
            else if(num==2){
                if(v.size()<2) {f=false; break;}
                int x=pos[i][0],y=pos[i][1];
                p[x]=v.back(); v.pop_back(); q[x]=i;
                q[y]=v.back(); v.pop_back(); p[y]=i;
            }
            else{
                v.push_back(i); v.push_back(i);
            }
        }
        if(!f) {puts("NO"); continue;}
        puts("YES");
        for(int i=1;i<=n;i++) printf("%d%c",p[i],i==n?'\n':' ');
        for(int i=1;i<=n;i++) printf("%d%c",q[i],i==n?'\n':' ');
    }
    return 0;
}

