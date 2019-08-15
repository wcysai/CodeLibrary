#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN],deq[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int s=0,t=0;
    for(int i=1;i<=n;i++)
    {
        while(s<t&&a[deq[t-1]]>=a[i]) t--;
        deq[t++]=i;
        if(i-k+1>=0)
        {
            b[i-k+1]=deq[s];
            if(deq[s]==i-k+1) s++;
        }
    }
    for(int i=1;i<=n-k+1;i++)
    {
        if(b[i]!=i)
        {
            sort(a+i,a+i+k);
            break;
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    puts("");
    return 0;
}
