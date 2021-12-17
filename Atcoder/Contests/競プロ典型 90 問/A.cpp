#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l,k,a[MAXN];
bool check(int x)
{
    int cnt=0,pos=1,last=0;
    while(pos<=n+1)
    {
        while(pos+1<=n+1&&a[pos]-last<x) pos++;
        if(a[pos]-last>=x) cnt++,last=a[pos]; else break; 
    }
    return cnt-1>=k;
}
int main()
{
    scanf("%d%d%d",&n,&l,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[n+1]=l;
    int l=0,r=INF;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    printf("%d\n",l);
    return 0;
}