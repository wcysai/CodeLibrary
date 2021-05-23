#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
bool check(int x)
{
    int st=1;
    while(st<=n)
    {
        int now=st;
        while(now<n&&a[now+1]-a[st]<=2*x) now++;
        if(now==n) return true;
        if(now<=st+1) return false;
        if(st!=1&&now==st+2) return false;
        st=now-1; 
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans;
    if(n==2) {printf("%d\n",(a[2]-a[1])/2); return 0;}
    int l=0,r=INF;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) r=mid; else l=mid;
    }
    printf("%d\n",r);
    return 0;
}