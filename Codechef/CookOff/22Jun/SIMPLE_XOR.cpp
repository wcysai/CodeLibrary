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
int t,l,r,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        if(r-l>=10)
        {
            for(int i=l;i+3<=r;i++)
            {
                if((i^(i+1)^(i+2)^(i+3))==0) {printf("%d %d %d %d\n",i,i+1,i+2,i+3); break;}
            }
        }
        else
        {
            bool f=false;
            for(int i=l;i<=r;i++)
                for(int j=i+1;j<=r;j++)
                    for(int k=j+1;k<=r;k++)
                    {

                        for(int last=k+1;last<=r;last++)
                        {
                            if(f) break;
                            if((i^j^k^last)==0)
                            {
                                f=true;
                                printf("%d %d %d %d\n",i,j,k,last);
                            }
                        }
                    }
            if(!f) puts("-1");
        }
    }
    return 0;
}

