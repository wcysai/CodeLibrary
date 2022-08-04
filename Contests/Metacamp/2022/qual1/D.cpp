#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n,a[MAXN];
int bit[MAXN];
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
    while(i<=n+1)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
ll k;
//val^2=a/b, a=#of1, b=#of 0, when b=0, val=0
bool check(db x)
{
    //check #of a-bval^2>=0 excluding those b=0 
    memset(bit,0,sizeof(bit));
    vector<db> v;
    int zero=0,one=0;
    v.push_back(0);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) zero++; else one++;
        db res=one-zero*x*x;
        v.push_back(res);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int id=lower_bound(v.begin(),v.end(),0)-v.begin()+1;
    add(id,1);
    zero=one=0;
    ll cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) zero++; else one++;
        db res=one-zero*x*x;
        int id=lower_bound(v.begin(),v.end(),res)-v.begin()+1;
        cnt+=sum(id);
        //printf("i=%d id=%d sum=%d\n",i,id,sum(id));
        add(id,1);
    }
    int cc=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            cc++;
        }
        else 
        {
            cnt-=1LL*cc*(cc+1)/2;
            cc=0;
        }
    }
    cnt-=1LL*cc*(cc+1)/2;
    //printf("x= %.15Lf cnt=%lld\n",x,cnt);
    return cnt>=k;
}
int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    db l=0.0,r=n;
    for(int i=0;i<100;i++)
    {
        db mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    printf("%.15Lf\n",l);
    return 0;
}

