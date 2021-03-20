#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],cnt[MAXN];
int main()
{
    scanf("%d",&n);
    int maxi=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        maxi=max(maxi,a[i]);
        cnt[a[i]]++;
    }
    if(maxi==1)
    {
        if(n==2) puts("Possible"); else puts("Impossible");
        return 0;
    }
    bool f=true;
    if(maxi%2==0)
    {
        for(int i=maxi/2+1;i<=maxi;i++)
        {
            if(cnt[i]<2) f=false;
            cnt[i]-=2;
        }
        if(cnt[maxi/2]!=1) f=false;
        for(int i=0;i<maxi/2;i++) if(cnt[i]>0) f=false;
    }
    else
    {
        for(int i=maxi/2+1;i<=maxi;i++)
        {
            if(cnt[i]<2) f=false;
            cnt[i]-=2;
        }
        for(int i=0;i<=maxi/2+1;i++) if(cnt[i]>0) f=false;
    }
    if(f) puts("Possible"); else puts("Impossible");
    return 0;
}