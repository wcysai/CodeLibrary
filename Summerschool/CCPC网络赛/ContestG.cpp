#include<bits/stdc++.h>
#define MAXN 40
using namespace std;
typedef long long ll;
ll cal(ll n,int k)
{
    ll ans=0;
    int digit[MAXN];
    ll mi[MAXN];
    int i=1;
    while(n>0)
    {
        digit[i]=n%k;
        n=n/k;
        i++;
    }
    i--;
    for(int j=1;j<=(i/2);j++)
        swap(digit[j],digit[i+1-j]);
    if(i==0) return 0;
    if(i==1) return digit[1];
    if(i==2) return digit[1]<=digit[2]?digit[1]+k-1:digit[1]+k-2;
    mi[2]=k-1;
    mi[1]=k-1;
    for(int j=3;j<MAXN;j++)
        mi[j]=(k*mi[j-2]);
    for(int j=1;j<i;j++)
        ans=ans+mi[j];
    int f=1;
    for(int j=(i+1)/2;j>=1;j--)
    {
        if(digit[j]<digit[i+1-j]) break;
        else if(digit[j]>digit[i+1-j]){f=0; break;}
    }
    if(!f) digit[(i+1)/2]--;
    ll s=0;
    for(int j=1;j<=(i+1)/2;j++)
        if(j==1) s=s+digit[j]-1; else s=(s*k+digit[j]);
    return (s+ans+1);
}
int main()
{
    int t,L,R,l,r;
    scanf("%d",&t);
    int k=1;
    while(k<=t)
    {
        scanf("%d %d %d %d",&L,&R,&l,&r);
        ll s=0;
        for(int i=l;i<=r;i++)
        {
            ll p=cal(R,i)-cal(L-1,i);
            s=s+p*i+R-L+1-p;
        }
        printf("Case #%d: %I64d\n",k,s);
        k++;
    }
    return 0;
}
