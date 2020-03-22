#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int c,q,g;
int w[MAXN],sumf,sumc;
int main()
{
    scanf("%d",&c);
    while(c--)
    {
        sumf=sumc=0;
        scanf("%d%d",&q,&g);
        double s=0;
        for(int i=1;i<=q;i++) 
        {
            scanf("%d",&w[i]);
            s+=1.0*w[i]*w[i];
        }
        for(int i=1;i<=q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            sumf+=x; sumc+=y;
        }
        double delta=g*sqrt(s);
        if(sumc<=0) printf("%.15f\n",0); else printf("%.15f\n",1.0*sumc/(delta-sumf));
    }
    return 0;
}