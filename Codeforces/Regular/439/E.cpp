#include<bits/stdc++.h>
#define MAXN 2550
#define MAXQ 100005
using namespace std;
int bit[MAXN+1][MAXN+1],n,m,q;
struct rect
{
    int a,b,c,d;
}mem[MAXQ];
int sum(int i,int j)
{
    int t,s=0;
    while(i>0)
    {
        t=j;
        while(t>0)
        {
            s+=bit[i][t];
            t-=t&-t;
        }
        i-=i&-i;
    }
    return s;
}
void add(int i,int j,int x)
{
    int t;
    while(i<=n)
    {
        t=j;
        while(t<=n)
        {
            bit[i][t]+=x;
            t+=t&-t;
        }
        i+=i&-i;
    }
}
int main()
{
    scanf("%d %d %d",&n,&m,&q);
    memset(bit,0,sizeof(bit));
    int k=0;
    for(int i=0;i<q;i++)
    {
        int t,r1,c1,r2,c2;
        scanf("%d %d %d %d %d",&t,&r1,&c1,&r2,&c2);
        if(t==1)
        {
            k++;
            mem[k].a=r1;
            mem[k].b=c1;
            mem[k].c=r2;
            mem[k].d=c2;
            add(r1,c1,1);
            add(r1,c2+1,-1);
            add(r2+1,c1,-1);
            add(r1+1,r2+1,1);
        }
        else if (t==2)
        {
            int x=sum(r1,c1);
            add(r1,c1,-x);
            add(r1,c2+1,x);
            add(r2+1,c1,x);
            add(r1+1,r2+1,-x);
        }
        else if(t==3)
        {
            int x=sum(r1,c1),y=sum(r2,c2);
            if(x==y) printf("YES\n"); else printf("NO\n");
        }
    }
    return 0;
}
