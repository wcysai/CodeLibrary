#include<bits/stdc++.h>
#define MAXN 10000000
using namespace std;
typedef long long ll;
ll k=100000000000-2;
ll N[11]={0,0,32,26,444,1628,5906,80,126960,380882,2097152};
ll D[11]={0,0,126,126,1778,6510,23622,510,507842,1523526,8388606};
ll ulam[100000000];
int main()
{
    ll s=0;
    ulam[0]=0;
    for(int i=2;i<=10;i++)
    {
        ll d1=2,d2=4*i+4;
        for(int j=1;j<=3+i;j++)
            ulam[j]=(i+j)*2-1;
        int d=4+i,now=4*i+7;
        while(d<=N[i])
        {
            int cnt=0;
            if(*lower_bound(ulam,ulam+d,now-d1)==now-d1) cnt++;
            if(*lower_bound(ulam,ulam+d,now-d2)==now-d2) cnt++;
            if(cnt==1)
            {
                ulam[d]=now;
                d++;
                now+=2;
            }
            else
            {
                now+=2;
                continue;
            }
        }
        printf("%I64d\n",((k/N[i])*D[i])+ulam[k%N[i]]);
        if(k%N[i]==0) s+=(k/N[i]-1)*D[i]+ulam[N[i]]; else s+=((k/N[i])*D[i])+ulam[k%N[i]];
    }
    printf("%I64d\n",s);
    return 0;
}
