#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
int n,cnth[MAXN],cntv[MAXN];
int ansh,ansv;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--; y--;
        if(cnth[x]) ansh+=2; else ansh+=4;
        if(x!=0) ansh+=2*min(cnth[x],cnth[x-1]);
        ansh+=2*min(cnth[x],cnth[x+1]);
        cnth[x]++;
        if(x!=0) ansh-=2*min(cnth[x],cnth[x-1]);
        ansh-=2*min(cnth[x],cnth[x+1]);
        if(cntv[y]) ansv+=2; else ansv+=4;
        if(y!=0) ansv+=2*min(cntv[y],cntv[y-1]);
        ansv+=2*min(cntv[y],cntv[y+1]);
        cntv[y]++;
        if(y!=0) ansv-=2*min(cntv[y],cntv[y-1]);
        ansv-=2*min(cntv[y],cntv[y+1]);
        printf("%d %d\n",ansh,ansv);
    }
    return 0;
}