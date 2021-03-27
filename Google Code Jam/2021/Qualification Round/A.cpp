#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0;
        for(int i=1;i<=n-1;i++)
        {
            int id=-1;
            for(int j=i;j<=n;j++) if(a[j]==i) {id=j; break;}
            ans+=id-i+1;
            reverse(a+i,a+id+1);
        }
        printf("Case #%d: %d\n",_,ans);
    }
    return 0;
}