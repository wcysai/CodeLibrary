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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int s=0;
        bool f1=false,f2=false;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); s+=a[i];}
        for(int i=1;i<=n-1;i++){
            if(a[i]==-1&&a[i+1]==-1) f1=true;
            else if(a[i]+a[i+1]==0) f2=true;
        }
        if(f1) printf("%d\n",s+4); else if(f2) printf("%d\n",s); else printf("%d\n",s-4);
    }
    return 0;
}

