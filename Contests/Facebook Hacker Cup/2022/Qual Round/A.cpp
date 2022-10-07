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
int T,n,k;
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&n,&k);
        map<int,int> mp;
        bool f=true;
        for(int i=1;i<=n;i++) 
        {
            int x;
            scanf("%d",&x);
            mp[x]++;
            if(mp[x]>2) f=false;
        }
        if(2*k<n) f=false;
        printf("Case #%d: ",t);
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

