#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 50000
using namespace std;
struct num
{
    int l,r,c;
}dat[MAXN];
int bit[MAXN+1],n;
bool used[MAXN];
bool cmp(const num &a,const num &b)
{
    if(a.r==b.r) return a.l<b.l;
    else return a.r<b.r;
}
int sum(int x)
{
    int s=0;
    for(int i=x;i>0;i-=i&-i)
        s+=bit[i];
    return s;
}
void add(int x,int d)
{
    for(int i=x;i<=MAXN;i+=i&-i)
        bit[i]+=d;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d",&dat[i].l,&dat[i].r,&dat[i].c);
    sort(dat,dat+n,cmp);
    memset(used,false,sizeof(used));
    memset(bit,0,sizeof(bit));
    int res=0;
    for(int i=0;i<n;i++)
    {
        int picked=sum(dat[i].r+1)-sum(dat[i].l);
        if(dat[i].c>picked)
        {
        int remain=dat[i].c-picked;
        res+=remain;
        int tail=dat[i].r;
        while(remain)
        {
            if(!used[tail])
            {
                used[tail]=true;
                add(tail+1,1);
                remain--;
            }
            tail--;
        }
        }
    }
printf("%d\n",res);
return 0;
}
