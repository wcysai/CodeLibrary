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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int x=(1<<31)-1;
        for(int i=1;i<=n;i++){ scanf("%d",&a[i]); x&=a[i];}
        if(x) {printf("%d\n",1); continue;}
        int now=(1<<31)-1,cnt=0;
        for(int i=1;i<=n;i++){
            now&=a[i];
            if(now==0) {cnt++; now=(1<<31)-1;}
        }
        printf("%d\n",cnt);
    }
    return 0;
}

