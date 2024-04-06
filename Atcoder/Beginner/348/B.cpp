#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,x[MAXN],y[MAXN];
int get_dist2(int i,int j){
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++){
        int ans=(i==1?2:1);
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(get_dist2(j,i)>get_dist2(ans,i)) ans=j;
        }
        printf("%d\n",ans);
    }
    return 0;
}

