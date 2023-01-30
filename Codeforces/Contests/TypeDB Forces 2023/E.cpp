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
int t,n,k,x;
vector<int> ans[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&x);
        int s=0;
        for(int i=1;i<=n;i++) s^=i;
        int tmp=(k&1)?x:0;
        if(s!=tmp) {puts("NO"); continue;}
        int tot=0;
        for(int i=1;i<=n;i++){
            if(((i^x)<i)){
                if(tot<k) ++tot;
                ans[tot].push_back(i); if(i!=x) ans[tot].push_back(i^x);
            }
            else if((i^x)>n){
                ans[k].push_back(i); 
            }
        }
        bool f=true;
        for(int i=1;i<=k;i++) if(!ans[i].size()) f=false;
        if(!f) puts("NO");
        else
        {
            puts("YES");
            for(int i=1;i<=k;i++){
                printf("%d",(int)ans[i].size());
                for(auto x:ans[i]) printf(" %d",x);
                puts("");
            }
        }
        for(int i=1;i<=k;i++) ans[i].clear();
    }
    return 0;
}

