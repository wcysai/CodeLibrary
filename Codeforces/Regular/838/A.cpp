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
    while(t--)
    {
        scanf("%d",&n);
        int s=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        if(s%2==0) {puts("0"); continue;}
        int ans=INF;
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            int x=a[i];
            while((x&1)==(a[i]&1)) {x>>=1; cnt++;}
            ans=min(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}

