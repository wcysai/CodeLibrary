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
map<int,int> cnt;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cnt.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        if(n==1)
        {
            puts("YES");
            printf("%d\n%d\n",a[1],a[1]);
            continue;
        }
        bool f=true;
        for(auto p:cnt) if(p.S*2>n) f=false;
        if(!f) {puts("NO"); continue;}
        if(cnt.size()==2) {puts("NO"); continue;}
        puts("YES");
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ');
        for(int i=1;i<=n;i++) printf("%d%c",a[(i+n/2-1)%n+1],i==n?'\n':' ');
    }
    return 0;
}

