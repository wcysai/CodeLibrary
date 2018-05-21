#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n,m;
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %lld",&n,&m);
        ll sum=(n-1)*n*n/2,x=m;
        for(int j=0;j<min(n-1,x);j++)
        {
            sum-=(n-1)+j*(n-2);
            m--;
        }
        if(m==0) printf("%lld\n",2*sum);
        else printf("%lld\n",2*max(sum-m,(n-1)*n/2));
    }
   return 0;
}
