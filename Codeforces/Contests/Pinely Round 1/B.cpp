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
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        set<int> s;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        if(s.size()==1) puts("1");
        else if(s.size()==2)
        {
            assert(n%2==0);
            printf("%d\n",n/2+1);
        }
        else printf("%d\n",n);
    }
    return 0;
}

