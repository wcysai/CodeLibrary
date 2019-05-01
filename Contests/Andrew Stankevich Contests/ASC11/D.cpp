#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,a[MAXN];
map<int,int> cnt;
int main()
{
    freopen("integer.in","r",stdin);
    freopen("integer.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        cnt[a[i]-i]++;
    }
    int maxi=-1,id=0;
    for(auto x:cnt) 
    {
        if(x.S>maxi)
        {
            maxi=x.S;
            id=x.F;
        }
    }
    printf("%d\n",n-maxi);
    for(int i=1;i<=n;i++) printf("%d ",id+i);
    return 0;
}
