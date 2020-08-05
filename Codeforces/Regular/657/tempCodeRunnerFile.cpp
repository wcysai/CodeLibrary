#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int fa[MAXN];
void construct(int l,int r)
{
    int ind=l-1; 
    for(int i=2;i<=r-l+1;i++) fa[i+ind]=i/2+ind;
}
int main()
{
    scanf("%d%d",&n,&k);
    if(n<4&&k>0) {puts("NO"); return 0;}
    if(k>(n-2)/2) {puts("NO"); return 0;}
    puts("YES");
    int now=1;
    while(k>0)
    {
        k--;
        fa[now+1]=now;
        fa[now+2]=now;
        now+=2;
    }
    construct(now,n);
    for(int i=1;i<=n;i++) printf("%d ",fa[i]);
}