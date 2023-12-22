#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
bool has[MAXN];
bitset<5001> bs[MAXN];
bool upd[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    bs[0].set(0);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) bs[i].reset();
        for(int i=1;i<=n;i++)
            for(int j=0;j<=n;j++)
                upd[i][j]=false;
        for(int i=1;i<=n;i++){
            bs[i]|=bs[i-1];
            int cur=0;
            for(int j=0;j<=n;j++) has[j]=false;
            for(int j=i;j>=1;j--){
                has[a[j]]=true;
                if(has[cur]){
                    while(has[cur]) cur++;
                    if(upd[j][cur]) continue;
                    for(int k=bs[j-1]._Find_first();k!=bs[j-1].size();k=bs[j-1]._Find_next(k)) 
                        bs[i].set(cur^k);
                    upd[j][cur]=true;
                }
            }
        }
        int ans=0;
        for(int k=bs[n]._Find_first();k!=bs[n].size();k=bs[n]._Find_next(k)) ans=max(ans,k);
        printf("%d\n",ans);
    }
    return 0;
}

