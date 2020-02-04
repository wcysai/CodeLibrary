#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll bit[MAXN+1];
int T,n,q;
ll sum(int i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,ll x)
{
    while(i<=MAXN)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0;i<q;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(x==1) 
            {
                ll res=sum(y)-sum(y-1);
                add(y,z-res);
            }
            else printf("%lld\n",sum(z)-sum(y-1));
        }
    }
    return 0;
}