#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int s=0;
        for(int i=1;i<=n;i++) s+=a[i];
        if(s==x) {puts("NO"); continue;}
        puts("YES");
        s=0;
        for(int i=1;i<=n;i++)
        {
            s+=a[i];
            if(s==x) {swap(a[i],a[i+1]); break;}
        }
        for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
    }
    return 0;
}