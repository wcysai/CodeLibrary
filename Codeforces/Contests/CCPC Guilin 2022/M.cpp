#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
ll ans[MAXN];
int bit[MAXN+1];
bool rev;
int shift;
int sum(int i)
{
    int s=0;
    while(i)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
string str;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        ans[0]+=(i-1-sum(a[i]));
        add(a[i],1);
    }
    for(int i=1;i<=n-1;i++)
        ans[i]=ans[i-1]-(a[i]-1)+(n-a[i]);
    printf("%lld\n",ans[0]);
    cin>>str;
    for(int i=0;i<m;i++)
    {
        if(str[i]=='R')
        {
            rev=!rev;
        }
        else 
        {
            if(rev) shift=(shift+n-1)%n;
            else shift=(shift+1)%n;
        }
        ll res=(rev?1LL*n*(n-1)/2-ans[shift]:ans[shift]);
        printf("%d",res%10);
    }
    printf("\n");
    return 0;
}

