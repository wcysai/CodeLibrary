#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]=a[i]/10+(i-1);
    }
    int mini=INF;
    for(int i=1;i<=n;i++) mini=min(mini,a[i]);
    int pos=-1,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==mini)
        {
            cnt++;
            pos=i;
        }
    }
    if(cnt==1)
    {
        int mini2=INF;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==mini) continue;
            mini2=min(mini2,a[i]);
        }
        ll ans=a;
        for(int i=1;i<=n;i++)
    }

}
