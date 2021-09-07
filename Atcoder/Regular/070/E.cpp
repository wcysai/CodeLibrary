#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n,l[MAXN],r[MAXN];
multiset<ll> L,R;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&l[i],&r[i]);
    L.insert(l[0]); R.insert(l[0]);
    //L/R maintaining changes of slopes 
    ll lshift=0,rshift=0,res=0;
    for(int i=1;i<n;i++)
    {
        //flatten
        //L move left by len[i]
        lshift+=(r[i]-l[i]);
        //R move rright by len[i-1]
        rshift+=(r[i-1]-l[i-1]);
        //merge with f_i
        ll lb=*(--L.end())-lshift,rb=*R.begin()+rshift;
        res+=max(0LL,max(lb-l[i],l[i]-rb));
        L.insert(l[i]+lshift); R.insert(l[i]-rshift);
        while(*(--L.end())-lshift>*R.begin()+rshift)
        {
            ll x=*(--L.end())-lshift,y=*R.begin()+rshift;
            L.erase(--L.end()); R.erase(R.begin());
            L.insert(y+lshift); R.insert(x-rshift);
        }
    }
    printf("%lld\n",res);
    return 0;
}