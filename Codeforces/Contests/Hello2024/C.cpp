#include<bits/stdc++.h>
#define MAXN 200005
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
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        vector<int> v1,v2;
        v1.push_back(INF); v2.push_back(INF);
        int ans=0;
        for(int i=1;i<=n;i++){
            int x=v1.back(),y=v2.back();
            if(x<a[i]&&y<a[i]){
                ans++;
                if(x<=y) v1.push_back(a[i]); else v2.push_back(a[i]);
            }
            else if(x>=a[i]&&y>=a[i]){
                if(x<=y) v1.push_back(a[i]); else v2.push_back(a[i]);
            }
            else{
                if(x>=a[i]) v1.push_back(a[i]);
                else v2.push_back(a[i]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

