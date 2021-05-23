#include<bits/stdc++.h>
#define MAXN 100005
#define INF 120000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
ll a[5],b[5],c[5];
int perm[5];
int main()
{
    scanf("%d",&t);
    int kase=0;
    while(t--)
    {
        kase++;
        perm[0]=0; perm[1]=1; perm[2]=2;
        scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
        bool f=false;
        do
        {
            for(int i=0;i<12;i++)
                for(int j=0;j<60;j++)
                {
                    b[0]=a[perm[0]];//hour
                    b[1]=a[perm[1]];//minute
                    b[2]=a[perm[2]];//second
                    if(f) break;
                    b[0]-=30LL*i*INF;
                    b[0]-=j*INF/2;
                    b[1]-=6LL*j*INF;
                    bool flag=false;
                    for(int ii=-1;ii<=1;ii++)
                        for(int jj=-1;jj<=i;jj++)
                            for(int kk=-1;kk<=i;kk++)
                            {
                                if(f) break;
                                c[0]=b[0]+ii*360LL*INF;
                                c[1]=b[1]+jj*360LL*INF;
                                c[2]=b[2]+kk*360LL*INF;
                                if((c[1]-12LL*c[0])%11) continue;
                                ll h=(c[1]-12LL*c[0])/11;
                                if(c[2]+h!=720LL*(c[0]+h)) continue;
                                c[0]+=h; c[1]+=h; c[2]+=h;
                                if(c[0]<0||c[0]>=360LL*INF) continue;
                                if(c[1]<0||c[1]>=360LL*INF) continue;
                                if(c[2]<0||c[2]>=360LL*INF) continue;
                                f=true;
                                printf("Case #%d: %lld %lld %lld %lld\n",kase,i,j,c[0]/1000000000LL,c[0]%1000000000LL);
                            }
                }
            if(f) break;
        }while(next_permutation(perm,perm+3));
    }
    return 0;
}