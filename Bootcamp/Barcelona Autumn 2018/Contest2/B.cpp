/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-27 17:57:34
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXK 10005
#define INF 1000000000
#define MOD1 19260817
#define INV1 9630409
#define MOD2 998244353
#define INV2 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,n,k;
ll t;
int st[MAXN],x;
ll b[MAXK];
char str[10];
ll hashk1,hashk2;
ll p1[MAXN],p2[MAXN];
int main()
{
    scanf("%lld",&T);
    bool halt;
    ll tot=0;
    p1[0]=p2[0]=1;
    for(ll i=1;i<=10001;i++) 
    {
        p1[i]=2LL*p1[i-1]%MOD1;
        p2[i]=2LL*p2[i-1]%MOD2;
    }
    while(T--)
    {
        printf("CASE %lld:\n",++tot);
        halt=false;
        scanf("%lld%lld",&k,&n);
        hashk1=hashk2=0;
        for(ll i=0;i<k;i++) scanf("%lld",&b[i]);
        for(ll i=k-1;i>=0;i--)
        {
            hashk1=(2LL*hashk1+b[i])%MOD1;
            hashk2=(2LL*hashk2+b[i])%MOD2;
        }
        //printf("%lld %lld\n",hashk1,hashk2);
        t=0;
        ll hash1=0,hash2=0;
        for(ll i=0;i<n;i++)
        {
            scanf("%s",str);
            if(str[1]=='U')
            {
                scanf("%d",&x);
                if(halt) continue;
                st[t++]=x;
                hash1=(2LL*hash1+(x&1))%MOD1;
                hash2=(2LL*hash2+(x&1))%MOD2;
                if(t>k)
                {
                    hash1=(hash1-(st[t-k-1]&1)*p1[k]+MOD1)%MOD1;
                    hash2=(hash2-(st[t-k-1]&1)*p2[k]+MOD2)%MOD2;
                }
                if(t>=k&&hash1==hashk1&&hash2==hashk2)
                {
                    //puts("done");
                    t-=k;
                    hash1=hash2=0;
                    for(ll i=max(0LL,t-k);i<t;i++)
                    {
                        hash1=(2LL*hash1+(st[i]&1))%MOD1;
                        hash2=(2LL*hash2+(st[i]&1))%MOD2;
                    }
                }
            }
            else if(str[0]=='P')
            {
                if(halt) continue;
                if(t==0) {puts("ERROR"); halt=true;}
                else
                {
                    printf("%d\n",st[t-1]);
                    t--;
                    hash1=1LL*(hash1-(st[t]&1))*INV1%MOD1;
                    hash2=1LL*(hash2-(st[t]&1))*INV2%MOD2;
                    if(t>=k)
                    {
                        hash1=(hash1+(st[t-k]&1)*p1[k-1])%MOD1;
                        hash2=(hash2+(st[t-k]&1)*p2[k-1])%MOD2;
                    }
                }
            }
            else if(str[0]=='A')
            {
                if(halt) continue;
                if(t<2) {puts("ERROR"); halt=true;}
                else
                {
                    int x=st[t-1]+st[t-2];
                    t--;
                    hash1=1LL*(hash1-(st[t]&1))*INV1%MOD1;
                    hash2=1LL*(hash2-(st[t]&1))*INV2%MOD2;
                    if(t>=k)
                    {
                        hash1=(hash1+(st[t-k]&1)*p1[k-1])%MOD1;
                        hash2=(hash2+(st[t-k]&1)*p2[k-1])%MOD2;
                    }
                    t--;
                    hash1=1LL*(hash1-(st[t]&1))*INV1%MOD1;
                    hash2=1LL*(hash2-(st[t]&1))*INV2%MOD2;
                    if(t>=k)
                    {
                        hash1=(hash1+(st[t-k]&1)*p1[k-1])%MOD1;
                        hash2=(hash2+(st[t-k]&1)*p2[k-1])%MOD2;
                    }
                    st[t++]=x;
                    hash1=(2LL*hash1+(x&1))%MOD1;
                    hash2=(2LL*hash2+(x&1))%MOD2;
                    if(t>k)
                    {
                        hash1=(hash1-(st[t-k-1]&1)*p1[k]+MOD1)%MOD1;
                        hash2=(hash2-(st[t-k-1]&1)*p2[k]+MOD2)%MOD2;
                    }
                    if(t>=k&&hash1==hashk1&&hash2==hashk2)
                    {
                        //puts("done");
                        t-=k;
                        hash1=hash2=0;
                        for(ll i=max(0LL,t-k);i<t;i++)
                        {
                            hash1=(2LL*hash1+(st[i]&1))%MOD1;
                            hash2=(2LL*hash2+(st[i]&1))%MOD2;
                        }
                    }
                }
            }
            else
            {
                if(halt) continue;
                t=0;hash1=0;hash2=0;
            }
            //printf("%lld %lld\n",hash1,hash2);
        }
    }
    return 0;
}
/*
100
5 100
1 0 0 0 0
PUSH 3
PUSH 5
PUSH 2
PUSH 2
PUSH 2
PUSH 2
PUSH 2
PUSH 2
PUSH 2
PUSH 2
PUSH 5
PUSH 5
ADD
*/
