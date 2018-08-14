#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 1000000000000000000
using namespace std;
typedef long long ll;
int t,n;
ll k;
ll pow2[63];
ll pal[100],evenpal[100],oddpal[100],both[100];
char str[MAXN];
int main()
{
    scanf("%d",&t);
    pow2[0]=1;
    int cnt=0;
    while(pow2[cnt]<=MAXK)
    {
        cnt++;
        pow2[cnt]=pow2[cnt-1]*2;
    }
    cnt++;
    pal[0]=1;
    int cnt2=1;
    while(true)
    {
        ll sum=pow2[(cnt2+1)/2];
        oddpal[cnt2]=pow2[((cnt2+1)/2+1)/2];
        ll evenall=pow2[cnt2/2];
        evenpal[cnt2]=pow2[(cnt2/2+1)/2];
        pal[cnt2]=oddpal[cnt2]*evenall+(sum-oddpal[cnt2])*evenpal[cnt2];
        if(pal[cnt2]>MAXK||pal[cnt2]<pal[cnt2-1]) break;
        both[cnt2]=evenpal[cnt2]*oddpal[cnt2];
        oddpal[cnt2]=oddpal[cnt2]*evenall;
        evenpal[cnt2]=evenpal[cnt2]*sum;
        cnt2++;
    }
    cnt2--;
    printf("%d\n",cnt2);
    for(int i=1;i<=cnt2;i++)
        printf("%d %lld\n",i,pal[i]);
    for(int i=0;i<t;i++)
    {
        scanf("%d%lld",&n,&k);
        printf("Case #%d: ",i+1);
        if(k>pal[n])
        {
            printf("NOT FOUND!\n");
            continue;
        }
        int id=0,state=0;
        while(n>0)
        {
            if(n==1)
            {
                if(k==1) str[id]='0'; else str[id]='1';
                break;
            }
            else if(n>cnt2)
            {
                str[id]=str[n-1-id]='0';
                n-=2;
                id++;
                continue;
            }
            else if(state==0)
            {
                if(k<=pal[n-2])
                {
                    str[id]=str[n-1-id]='0';
                    n-=2;
                    id++;
                    continue;
                }
                else if(k<=pal[n-2]+oddpal[n-2])
                {
                    str[id]='0';
                    str[n-1-id]='1';
                    n-=2;
                    id++;
                    state=1;
                    k-=pal[n];
                    continue;
                }
                else if(k<=pal[n-2]+2*oddpal[n-2])
                {
                    str[id]='1';
                    str[n-1-id]='0';
                    n-=2;
                    id++;
                    state=1;
                    k-=pal[n]+oddpal[n];
                    continue;
                }
                else
                {
                    str[id]=str[n-1-id]='1';
                    n-=2;
                    id++;
                    k-=pal[n]+oddpal[n];
                    continue;
                }
            }
            else if(state==1)
            {
                if(k<=evenpal[n-2])
                {
                    str[id]=str[n-1-id]='0';
                    n-=2;
                    id++;
                    state=2;
                    continue;
                }
                else
                {
                    str[id]=str[n-1-id]='1';
                    n-=2;
                    id++;
                    state=2;
                    k-=evenpal[n];
                    continue;
                }
            }
            else
            {
                if(k<=oddpal[n-2])
                {
                    str[id]=str[n-1-id]='0';
                    n-=2;
                    id++;
                    state=1;
                    continue;
                }
                else if(k<=2*oddpal[n-2])
                {
                    str[id]='0';
                    str[n-1-id]='1';
                    n-=2;
                    id++;
                    state=1;
                    k-=oddpal[n];
                    continue;
                }
                else if(k<=3*oddpal[n-2])
                {
                    str[id]='1';
                    str[n-1-id]='0';
                    n-=2;
                    id++;
                    state=1;
                    k-=2*oddpal[n];
                    continue;
                }
                else
                {
                    str[id]='1';
                    str[n-1-id]='1';
                    n-=2;
                    id++;
                    state=1;
                    k-=3*oddpal[n];
                    continue;
                }
            }
        }
        printf("%s\n",str);
    }
    return 0;
}
