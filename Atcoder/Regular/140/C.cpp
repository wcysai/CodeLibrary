#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,a[MAXN];
bool vis[MAXN];
int main()
{
    scanf("%d%d",&n,&x);
    vis[x]=true;
    if(x*2==n)
    {
        for(int i=x;i>=1;i--) printf("%d %d ",i,n+1-i);
        puts("");
    }
    else if(2*(x-1)==n)
    {
        for(int i=x;i<=n;i++) printf("%d %d ",i,n+1-i);
        puts("");
    }
    else if(2*x-1==n)
    {
        printf("%d ",x);
        for(int i=x-1;i>=1;i--) printf("%d %d ",i,n+1-i);
        puts("");
    }
    else if(x*2<=n)
    {
        printf("%d %d ",x,(n+1)/2+1); vis[(n+1)/2+1]=true;
        int l=(n+1)/2+1,r=(n+1)/2+1;
        while(l>=1||r<=n)
        {
            while(vis[l]&&l>=1) l--;
            if(l>=1) {printf("%d ",l); vis[l]=true;} else break;
            while(vis[r]&&r<=n) r++;
            if(r<=n) {printf("%d ",r); vis[r]=true;} else break;
        }
        puts("");
    }
    else
    {
        printf("%d %d ",x,n/2); vis[n/2]=true;
        int l=n/2+1,r=n/2;
        while(l>=1||r<=n)
        {
            while(vis[r]&&r<=n) r++;
            if(r<=n) {printf("%d ",r); vis[r]=true;} else break;
            while(vis[l]&&l>=1) l--;
            if(l>=1) {printf("%d ",l); vis[l]=true;} else break;
        }
        puts("");
    }
    return 0;
}

