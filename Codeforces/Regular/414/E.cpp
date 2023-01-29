#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int b[MAXN],c[MAXN];
int main()
{
    scanf("%d",&n);
    int maxi=0;
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); maxi=max(maxi,a[i]);}
    if(n==1) {printf("%d\n",a[1]); return 0;}
    if(n==2) {printf("%d %d\n",max(a[1],a[2]),max(a[1],a[2])); return 0;}
    for(int i=1;i<=n-1;i++) b[i]=max(a[i],a[i+1]);
    for(int i=1;i<=n-2;i++) c[i]=max(min(a[i],a[i+1]),min(a[i+1],a[i+2]));
    int l1=n/2,r1=(n&1?l1+1:l1),val1=max(b[l1],b[r1]);
    int r2=n/2,l2=(n&1?r2:r2-1),val2=max(c[l2],c[r2]);
    for(int i=0;i<=n-1;i++){
        if((n-i)&1){
            if(i==n-1) printf("%d ",maxi);
            else
            {
                printf("%d ",val2);
                if(l2>1) {l2--; val2=max(val2,c[l2]);}
                if(r2<n-2) {r2++; val2=max(val2,c[r2]);}
            }
        }
        else{
            printf("%d ",val1);
            if(l1>1) {l1--; val1=max(val1,b[l1]);}
            if(r1<n-1) {r1++; val1=max(val1,b[r1]);}
        }
    }
    return 0;
}

