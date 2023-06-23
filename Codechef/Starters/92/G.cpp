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
int n,q,k,a[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    assert(__builtin_popcount(n+1)==1);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        if(n<=20){
            vector<int> vv;
            int ans=(u^v); vv.push_back(u); vv.push_back(v);
            for(int i=1;i<=n;i++){
                if(i==u||i==v) continue;
                    int res=(u^v^i);
                    if(res>ans){
                        ans=res;
                        vv.clear();
                        vv.push_back(u); vv.push_back(i); vv.push_back(v); 
                    }
                }
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++){
                    if(i==u||i==v||j==u||j==v) continue;
                        int res=(u^v^i^j);
                        if(res>ans){
                            ans=res;
                            vv.clear();
                            vv.push_back(u); vv.push_back(i); vv.push_back(j); vv.push_back(v);
                        }
                    }
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++)
                    for(int k=j+1;k<=n;k++){
                        if(i==u||i==v||j==u||j==v||k==u||k==v) continue;
                        int res=(u^v^i^j^k);
                        if(res>ans){
                            ans=res;
                            vv.clear();
                            vv.push_back(u); vv.push_back(i); vv.push_back(j); vv.push_back(k); vv.push_back(v);
                        }
                    }
            printf("%d %d\n",ans,(int)vv.size());
            for(auto x:vv) printf("%d ",x);
            puts(""); continue;
        }
        if((u^v)==n){
            printf("%d %d\n%d %d\n",n,2,u,v);
        }
        else if(u!=n&&v!=n) printf("%d %d\n%d %d %d\n",n,3,u,(n^u^v),v);
        else if(n==3){
            printf("%d %d\n%d %d\n",n,2,u,v);
        }
        else{
            for(int i=1;i<=n;i++){
                if(i!=u&&i!=v&&((n^i^u^v)!=v)&&((n^i^u^v)!=u)&&((n^i^u^v)!=i)){
                    printf("%d %d\n%d %d %d %d\n",n,4,u,i,(n^i^u^v),v);
                    break;
                }
            }
        }
    }
    return 0;
}
