#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],suf[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        suf[n+1]=(1<<30)-1;
        for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
        for(int i=n;i>=1;i--) suf[i]=(suf[i+1]&a[i]);
        int x=suf[1],s=(1<<30)-1,cnt=1;
        for(int i=1;i<=n;i++)
        {
            s&=a[i];
            if(s==x)
            {
                if(i==n||suf[i+1]>x) break;
                cnt++; s=(1<<30)-1;
            }
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}

