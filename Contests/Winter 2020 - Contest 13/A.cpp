#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int ask(int x,int y)
{
    printf("? %d %d\n",x,y);
    fflush(stdout);
    int z;
    scanf("%d",&z);
    return z;
}
void answer()
{
    printf("!");
    for(int i=1;i<=n;i++) printf(" %d",a[i]);
    printf("\n");
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    int last=0;
    for(int i=2;i<=n;i++) a[i]=ask(1,i);
    int x=ask(n-1,n);
    a[1]=(a[n-1]+a[n]-x)/2;
    for(int i=2;i<=n;i++) a[i]-=a[1];
    answer();
    return 0;
}