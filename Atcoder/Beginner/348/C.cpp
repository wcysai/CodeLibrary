#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
map<int,int> mp;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if(mp.find(y)==mp.end()) mp[y]=x;
        else mp[y]=min(mp[y],x);
    }
    int ans=0;
    for(auto p:mp) ans=max(ans,p.S);
    printf("%d\n",ans);
    return 0;
}

