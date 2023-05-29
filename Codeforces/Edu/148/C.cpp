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
int t,n,k,a[MAXN];
int st[MAXN],tt;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        tt=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            while(tt>0&&st[tt-1]==a[i]) tt--;
            while(tt>1&&(st[tt-2]>st[tt-1]&&st[tt-1]>a[i])) tt--;
            while(tt>1&&(st[tt-2]<st[tt-1]&&st[tt-1]<a[i])) tt--;
            st[tt++]=a[i];
        }
        printf("%d\n",tt);
    }
    return 0;
}

