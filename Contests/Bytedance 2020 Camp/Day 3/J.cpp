#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[MAXN];
ll bas[62];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ll cur=x;
        while(cur<(1LL<<60))
        {
            ll tmp=cur;
            for(int j=60;j>=0;j--)
            {
                if(tmp&(1ll<<j))
                {
                    if(!bas[j])
                    {
                        bas[j]=tmp;
                        break;
                    }
                    tmp^=bas[j];
                }
            }
            cur<<=1;
        }
    }
    for(int j=0;j<=60;j++) if(bas[j]) {printf("%lld\n",bas[j]); return 0;}
    assert(0);
}