#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef unsigned long long ull;
int t;
ull a,b,c,d;
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%llu%llu%llu%llu",&a,&b,&c,&d);
        if((a>>62&1)&&(b>>62&1)&&(c>>62&1)&&(d>>62&1)) {printf("18446744073709551616\n"); continue;}
        printf("%llu\n",a+b+c+d);
    }
    return 0;
}
