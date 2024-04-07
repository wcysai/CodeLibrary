#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int id=-1;
        for(int i=1;i<=n;i++) if(a[i]>a[k]) {id=i; break;}
        if(id==-1) {printf("%d\n",n-1); continue;}
        int ans=max(0,id-2);
        if(id<k){
            swap(a[k],a[id]);
            int res=(id==1?0:1);
            for(int i=id+1;i<=n;i++) if(a[id]>a[i]) res++; else break;
            ans=max(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}

