#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int inv[7],p[MAXN];
int n,s[MAXN],a[MAXN];
int find_num(int x)
{
    int l=0,r=2000;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(mid*(mid-1)/2<=x) l=mid; else r=mid;
    }
    return l;
}
int main()
{
    inv[1]=1; inv[2]=4; inv[3]=5; inv[4]=2; inv[5]=3; inv[6]=6;
    s[0]=0;
    scanf("%d",&n);
    p[0]=1;
    for(int i=1;i<=n;i++) p[i]=3*p[i-1]%7;
    int tot=0,now=1;
    while(n)
    {
        int x=find_num(n);
        for(int j=now;j<=(tot==0?now+x-2:now+x-1);j++) s[j]=tot;
        n-=x*(x-1)/2;
        now+=(tot==0?x-1:x);
        tot++; 
    }
    assert(tot<=7);
    for(int i=1;i<=now-1;i++) {a[i]=(s[i]-s[i-1])*p[i-1]%7; printf("%d",a[i]==0?7:a[i]);}
    return 0; 
}