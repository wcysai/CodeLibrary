#include<bits/stdc++.h>
#define MAXN 20000005
#define INF 1000000000
#define MOD 1000000007
#define INV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
int ans[MAXN];
int main()
{
    ans[1]=INV;
    int tmp=INV;
    for(int i=2;i<=20000000;i++) 
    {
        tmp=1LL*tmp*INV%MOD;
        ans[i]=1LL*ans[i-1]*(1+MOD-tmp)%MOD;
    }
    for(int i=2;i<=20000000;i++) ans[i]^=ans[i-1];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        printf("%d\n",ans[N]);
    }
    return 0;
}