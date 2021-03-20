#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[2*MAXN],b[2*MAXN];
int check(int x)
{
    for(int i=1;i<=2*n-1;i++) if(a[i]<x) b[i]=0; else b[i]=1;
    int l=n,r=n;
    while(l>=1)
    {
        if(b[l-1]==b[l]) return b[l];
        if(b[r+1]==b[r]) return b[r];
        l--; r++;
    }
    return b[n]^((n-1)&1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++) scanf("%d",&a[i]);
    int l=1,r=2*n;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)==1) l=mid; else r=mid;
    }
    printf("%d\n",l);
}