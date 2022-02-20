#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int pos=0,neg=0,zero=0,chg=INF;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]>0) pos++; else if(a[i]<0) neg++; else zero++;
            chg=min(chg,max(a[i],-a[i]));
        }
        if(zero) printf("%d\n",zero);
        else if(neg%2==0) puts("0");
        else printf("%d\n",chg+1);
    }
    return 0;
}