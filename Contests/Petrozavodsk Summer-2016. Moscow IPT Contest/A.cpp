#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define ratio sadkdoa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cnt,bit[MAXN];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    assert(i>0);
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void go(int x)
{
    cout<<x<<endl;
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    int last=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        //*lower_bound(dp,dp+n,x)=x;
        if(x<last) {go(0); continue;}
        int p=(n-x)-(sum(n)-sum(x));
        int q=(n-last)-(sum(n)-sum(last))-1;
        //printf("%d %d\n",p,q);
        if(sqrt(q)<sqrt(p)+1) go(1),last=x;
        else go(0);
        add(x,1);
    }
    //printf("%d\n",lower_bound(dp,dp+n,INF)-dp);
    //printf("%d\n",cnt);
    return 0;
}
