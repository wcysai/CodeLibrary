#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
typedef long long ll;
map<ll,bool> mymap;
int n;
ll a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    sort(a,a+n);
    int cnt=0;
    for(int i=n-1;i>=0;i--)
    {
        ll x=a[i];
        while(true)
        {
            if(x==1) break;
            if(mymap.find(x)!=mymap.end()) break;
            cnt++;
            mymap[x]=true;
            x/=2;
        }
    }
    printf("%d\n",cnt);
}
