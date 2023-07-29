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
int t,n,k;
P a[MAXN];
int ans[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i].F);
            a[i].S=i;
        }
        sort(a+1,a+n+1);
        int now=n,l=1,r=n,dec=0;
        bool f=true;
        while(l<=r){
            if(now==0) {f=false; break;}
            if(a[r].F-dec>r-l+1) {f=false; break;}
            if(a[l].F==dec){
                if(a[r].F==r-l+1+dec){
                    f=false; break;
                }
                while(l<=r&&a[l].F==dec){
                    ans[a[l].S]=-now;
                    l++;
                }
            }
            else if(a[r].F==r-l+1+dec){
                int cnt=0,val=r-l+1+dec;
                while(l<=r&&a[r].F==val){
                    ans[a[r].S]=now;
                    r--; cnt++;
                }
                dec+=cnt;
            }
            now--;
        }
        if(!f) puts("NO");
        else{
            puts("YES");
            for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
        }
    }
    return 0;
}

