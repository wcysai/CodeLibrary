#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,p[MAXN],pos[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&p[i]);
        pos[p[i]]=i;
    }
    if(n==2)
    {
        if(p[1]==1) puts("0"); else puts("1");
        return 0;
    }
    int nxt=pos[1]+1;
    if(nxt>n) nxt=1;
    assert(p[nxt]==2||p[nxt]==n);
    if(p[nxt]==2)
    {
        printf("%d\n",min(pos[1]-1,n+3-pos[1]));
    } 
    else
    {
        printf("%d\n",min(pos[1]+1,n-pos[1]+1));
    }
    return 0;
}