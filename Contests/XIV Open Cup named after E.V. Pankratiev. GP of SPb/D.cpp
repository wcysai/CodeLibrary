#include<bits/stdc++.h>
#define MAXN 3000005
#define MAXM (1<<21)
#define M (1<<5)
#define F first
#define S second
using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef pair<int,int> P;
int n;
uint block[MAXM],win[MAXM];
const int L=26-5;
const int LL=(1<<(L+5))-1;
string str;
const uint mask[5]=
{
    0xffff0000,
    0xff00ff00,
    0xf0f0f0f0,
    0xcccccccc,
    0xaaaaaaaa,
};
const uint mask2[5]=
{
    0x0000ffff,
    0x00ff00ff,
    0x0f0f0f0f,
    0x33333333,
    0x55555555,
};
uint mask3[40];
int main()
{
    freopen("forbidden-words.in","r",stdin);
    freopen("forbidden-words.out","w",stdout);
    for(int i=0;i<32;i++)
        for(int j=0;j<5;j++)
            if((i&(1<<j))==0) mask3[i]|=1<<(i^(1<<j));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        uint m=0;
        for(int j=0;j<(int)str.size();j++) m|=(1<<((int)str[j]-'a'));
        m=((~m)&((1u<<26)-1));
        block[m/M]|=(1<<(m%M));
    }
    for(int j=MAXM-1;j>=0;j--)
    {
        for(int i=0;i<21;i++) if(!(j&(1<<i))) block[j]|=block[j^(1<<i)];
        for(int i=0;i<5;i++) block[j]|=(block[j]>>(1<<(4-i)))&mask2[i];
    }
    for(int i=0;i<MAXM;i++)
    {
        win[i]=block[i];
        for(int j=0;j<21;j++)
            if((i&(1<<j))) win[i]|=~(win[i^(1<<j)]);
        for(int j=0;j<32;j++) if((win[i]&(1<<j))==0) win[i]|=mask3[j];
    }
    if(win[MAXM-1]&0x80000000) puts("First"); else puts("Second");
    return 0;
}
