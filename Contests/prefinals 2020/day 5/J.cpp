#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n;
int need[MAXN];
int ans[MAXN];
int main()
{
    need[0]=1;
    for(int i=1;i<=50;i++)
    {
        if(i&1) need[i]=2*((1<<(i/2+1))-1);
        else need[i]=3*((1<<(i/2))-1)+1;
    }
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<=50;i++) if(need[i]>=n-2) {ans=i; break;}
    printf("%d\n",ans);
    return 0;
}
