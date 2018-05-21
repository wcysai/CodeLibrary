#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int n,m;
int a[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    if(n==1) {printf("0\n"); return 0;}
    if(n==2)
    {
        if(m<3)
        {
            printf("0\n");
            return 0;
        }
        else
        {
            int x=(m+1)/2,y=m/2;
            printf("%lld\n",(ll)x*(x-1)+(ll)y*(y-1));
            return 0;
        }
    }
    if(n==3&&m==3)
    {
        printf("28\n");
        return 0;
    }
    else
    {
        long long sum=n*m;
        printf("%lld\n",sum*(sum-1)/2);
        return 0;
    }
    return 0;
}
