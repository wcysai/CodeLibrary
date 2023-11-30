#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],ans[MAXN];
vector<int> pos[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            pos[a[i]].push_back(i);
        }
        int fst=n+1,lst=0;
        for(int i=k;i>=1;i--){
            if(!pos[i].size()){
                ans[i]=0; continue;
            }
            else{
                int l=min(pos[i][0],fst),r=max(pos[i].back(),lst);
                ans[i]=2*(r-l+1);
                fst=min(fst,pos[i][0]); lst=max(lst,pos[i].back());
            }
        }
        for(int i=1;i<=k;i++) printf("%d%c",ans[i],i==k?'\n':' ');
        for(int i=1;i<=k;i++) pos[i].clear();
    }
    return 0;
}

