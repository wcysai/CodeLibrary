#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,a[MAXN];
int price[8]={0,7,27,41,49,63,78,108};
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int s=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            s+=price[x];
        }
        if(s>=120) s-=50;
        else if(s>=89) s-=30;
        else if(s>=69) s-=15;
        printf("%d\n",s);
    }
    return 0;
}