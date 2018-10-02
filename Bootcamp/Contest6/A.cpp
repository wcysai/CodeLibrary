/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-02 16:06:05
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ull;
typedef pair<int,int> P;
ull n;
ull lcm(ull a,ull b){return a*b/__gcd(a,b);}
ull mu[10]={0LL,1LL,-2LL,4LL,-8LL,16LL,-32LL,64LL,-128LL,256LL};
const ull INF=1000000000LL;
ull __sqrt(ull x)
{
    ull l=0,r=3037000500LL;
    //printf("%lld\n",r*r);
    while(r-l>1)
    {
        ull mid=(l+r)/2;
        if(mid*mid<=(ull)x) l=mid; else r=mid;
    }
    return (ull)l;
}

int main()
{
    scanf("%lld",&n);
    //printf("%llu\n",n);
    ull ans=__sqrt(n);
    //assert(ans*ans<=n);
    //assert((ans+1)*(ans+1)>n);
    //printf("%lld\n",ans);
    if(n<=INF*INF) {printf("%lld\n",ans);}
    else
    {
        for(ull i=1;i<=9;i++)
        {
            if(i*(INF*INF+1)>n) break;
            for(ull j=1;j<(1LL<<i);j++)
            {
                ull cnt=0,cm=1;
                for(ull k=0;k<i;k++) 
                {
                    if((j>>k)&1)
                    {
                        cnt++;
                        cm=lcm(cm,k+1);
                    }
                }
                //[mx\times (1e18+1), n]
                ull up;
                if(i==9) up=n;else 
                up=min(n,(i+1)*(INF*INF+1)-1);
                ull num=up/cm-(i*(INF*INF+1)-1)/cm;
                ull square_num=__sqrt(up/cm/cm)-__sqrt((i*(INF*INF+1)-1)/cm/cm);
                //printf("%ulld %ulld %ulld\n",mx,cnt,square_num);
                //if(i==3) printf("%llu %llu\n",num,square_num);
                assert(cnt>0&&cnt<=i);
                ans+=mu[cnt]*(num-2*square_num);
                //printf("%llu\n",ans);
            }
        }
        printf("%lld\n",ans);assert(ans<=n);
    } 
    return 0;
}

