#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P p[MAXN];
int dp[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        p[i].F=x+y;
        p[i].S=y-x;
    }
    sort(p+1,p+n+1);
    int ans=1,last=p[n].S;
    for(int i=n-1;i>=1;i--){
        if(p[i].S>last){
            ans++;
            last=p[i].S;
        }
    }
    printf("%d\n",ans);
    return 0;
}

