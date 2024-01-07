#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],cnt[MAXN];
int pre[MAXN],suf[MAXN];
bool del[MAXN];
vector<int> pos[MAXN];
void dele(int x){
    suf[pre[x]]=suf[x]; pre[suf[x]]=pre[x]; del[x]=true;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); pos[a[i]].push_back(i);}
        for(int i=1;i<=n;i++) {pre[i]=i-1; suf[i]=i+1; del[i]=false;}
        pre[n+1]=n; suf[0]=1;
        bool f=true;
        for(int i=n-1;i>=1;i--){
            for(auto x:pos[i]){
                bool flag=false;
                if(pre[x]>=1&&pre[x]<=n&&a[pre[x]]==i-1) flag=true;
                if(suf[x]>=1&&suf[x]<=n&&a[suf[x]]==i-1) flag=true;
                if(flag) dele(x);
            }
            for(int j=(int)pos[i].size()-1;j>=0;j--){
                int x=pos[i][j];
                if(del[x]) continue;
                bool flag=false;
                if(pre[x]>=1&&pre[x]<=n&&a[pre[x]]==i-1) flag=true;
                if(suf[x]>=1&&suf[x]<=n&&a[suf[x]]==i-1) flag=true;
                if(flag) dele(x);
            }
            for(auto x:pos[i]) if(!del[x]) f=false;
            if(!f) break;
        }
        if(pos[0].size()!=1) f=false;
        for(int i=0;i<=n-1;i++) pos[i].clear();
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

