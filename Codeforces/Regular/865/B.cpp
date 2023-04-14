#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int ask1(int x){
    printf("+ %d\n",x);
    fflush(stdout);
    int y; scanf("%d",&y);
    return y;
}
int ask2(int x,int y){
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int z; scanf("%d",&z); return z;
}
int res[MAXN],p[MAXN],x[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int l=1,r=n,tot=0;
        while(l<=r){
            x[++tot]=r; r--;
            x[++tot]=l; l++;
        }
        ask1(n); ask1(n+1);
        int maxi=0,len=0;
        for(int i=2;i<=n;i++){
            int y=ask2(1,i);
            if(y>len) {len=y; maxi=i;}
        }
        res[1]=len; res[maxi]=0;
        for(int i=2;i<=n;i++){
            if(i==maxi) continue;
            res[i]=ask2(i,maxi);
        }
        printf("!");
        for(int i=1;i<=n;i++) p[i]=x[1+res[i]];
        for(int i=1;i<=n;i++) printf(" %d",p[i]);
        for(int i=1;i<=n;i++) p[i]=x[n-res[i]];
        for(int i=1;i<=n;i++) printf(" %d",p[i]);
        printf("\n");
        fflush(stdout);
        int x; scanf("%d",&x);
    }
    return 0;
}

