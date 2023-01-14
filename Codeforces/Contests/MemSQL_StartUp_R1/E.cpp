
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
int n,tot;
int deg[MAXN],cycle[MAXN];
void euler(int v)
{
    for(;deg[v]<2;)
    {
        deg[v]++;
        if(deg[v]==1) euler(2*v%(n/2));
        else euler((2*v+1)%(n/2));
    }
    cycle[tot++]=v;
}
int main()
{
    scanf("%d",&n);
    if(n&1) {puts("-1"); return 0;}
    if(n==2) {puts("0 1 0"); return 0;}
    euler(0);
    reverse(cycle,cycle+tot);
    --tot;
    int now=0;
    printf("0");
    for(int i=1;i<=tot;i++)
    {
        if((2*cycle[i])%(n/2)==cycle[(i+1)%n]) now=2*now%n;
        else now=(2*now+1)%n;
        printf(" %d",now);
    }
    puts("");
    return 0;
}
