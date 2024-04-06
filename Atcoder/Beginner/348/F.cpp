#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN][MAXN];
bitset<2001> bs[MAXN];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=m;i++){
        vector<P> v;
        bitset<2001> b;
        for(int j=1;j<=n;j++) v.push_back(P(a[j][i],j));
        sort(v.begin(),v.end());
        vector<int> last;
        for(int j=0;j<n;j++){
            if(j==0||v[j-1].F!=v[j].F){
                for(auto x:last) bs[x]^=b;
                for(auto x:last) b[x]=0;
                last.clear();
            }
            last.push_back(v[j].S); b[v[j].S]=1;
        }
        for(auto x:last) bs[x]^=b;
        for(auto x:last) b[x]=0;
        last.clear();
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=bs[i].count();
    for(int i=1;i<=n;i++) if(bs[i][i]) ans--;
    ans/=2;
    printf("%d\n",ans);
    return 0;
}

