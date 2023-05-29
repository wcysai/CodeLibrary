#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        int l=n+1,r=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]){
                l=min(l,i);
                r=max(r,i);
            }
        }
        if(l==n+1) {
            int ansl=n+1,ansr=1,curl=1;
            for(int i=1;i<=n;i++){
                if(b[i]<b[i-1]){
                    curl=i;
                }
                if(i-curl+1>ansr-ansl+1) {ansl=curl; ansr=i;}
            }
            printf("%d %d\n",ansl,ansr);
        }
        else{
            while(l>1&&b[l-1]<=b[l]) l--;
            while(r<n&&b[r+1]>=b[r]) r++;
            printf("%d %d\n",l,r);
        }
    }
    return 0;
}

