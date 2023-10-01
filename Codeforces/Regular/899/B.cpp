#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int cnt[MAXN],tmp[MAXN];
vector<int> v[MAXN];
vector<int> in[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++) v[i].clear();
        for(int i=1;i<=50;i++) in[i].clear();
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            for(int j=0;j<k;j++){
                int x; scanf("%d",&x);
                v[i].push_back(x);
                cnt[x]++; in[x].push_back(i);
            }
        }
        int ans=0;
        for(int i=1;i<=50;i++){
            if(cnt[i]){
                for(int j=1;j<=50;j++) tmp[j]=cnt[j];
                for(auto x:in[i])
                    for(auto y:v[x]) tmp[y]--;
                int c=0;
                for(int j=1;j<=50;j++) if(tmp[j]) c++;
                ans=max(ans,c);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

