#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int l=1,r=n;
        bool f=false;
        while(l<=r)
        {
            if(a[l]==r-l+1)
            {
                l++; continue;
            }
            if(a[r]==r-l+1)
            {
                r--; continue;
            }
            for(int i=l;i<=r;i++)
            {
                if(a[i]==r-l+1)
                {
                    f=true;
                    printf("YES\n");
                    printf("%d %d %d\n",i-1,i,i+1);
                    break;
                }
            }
            if(f) break;
        }
        if(!f) puts("NO");
    }
    return 0;
}