#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef bitset<205> bs;
bs a1,b1,c1,a2,b2,c2;
void read(bs &b)
{
    int k;
    scanf("%d",&k);
    for(int i=k;i>=0;i--)
    {
        int x;
        scanf("%d",&x);
        if(x) b.set(i);
    }
}
bool iszero(bs &b)
{
    return b.count()==0;
}
void die()
{
    puts("No solution");
    exit(0);
}
bs mult(bs &a,bs &b)
{
    bs ret; ret.reset();
    for(int i=a._Find_first();i<205;i=a._Find_next(i))
        ret^=(b<<i);
    return ret;
}
int findlast(bs &b)
{
    if(iszero(b)) return -1;
    for(int i=b._Find_first();i<205;i=b._Find_next(i)) if(b._Find_next(i)>=205) return i;
    return -1;
}
void print(bs &b)
{
    if(iszero(b)) {puts("-1"); return;}
    int x=findlast(b);
    printf("%d",x);
    for(int i=x;i>=0;i--) if(b.test(i)) printf(" 1"); else printf(" 0");
    puts("");
}
bool div(bs a,bs b,bs &c)
{
    int x=findlast(b);
    while(!iszero(a))
    {
        int id=findlast(a);
        if(id<x) return false;
        c.flip(id-x);
        a^=b<<(id-x);
    }
    return true;
}
bs divrem(bs a,bs b)
{
    bs c; c.reset();
    int x=findlast(b);
    while(true)
    {
        int id=findlast(a);
        if(id<x) return a;
        c.flip(id-x);
        a^=b<<(id-x);
    }
}
bs extgcd(bs a,bs b,bs &x,bs &y)
{
    bs d=a;
    if(!iszero(b))
    {
        d=extgcd(b,divrem(a,b),y,x);
        bs r; r.reset();
        div(a,b,r);
        y=y^(mult(r,x));
    }
    else
    {
        x.reset(); x.set(0);
        y.reset();
    }
    return d;
}
int main()
{
    freopen("eq.in","r",stdin);
    freopen("eq.out","w",stdout);
    read(a1); read(b1); read(c1); read(a2); read(b2); read(c2);
    if(iszero(a1)&&iszero(b1)&&!iszero(c1)) die();
    if(iszero(a2)&&iszero(b2)&&!iszero(c2)) die();
    if(iszero(a1)&&iszero(b1)&&iszero(a2)&&iszero(c2))
    {
        print(c1); print(c2);
        return 0;
    }
    bs d=(mult(b1,a2)^mult(b2,a1));
    if(!iszero(d))
    {
        bs a=mult(c1,b2)^mult(c2,b1);
        bs b=mult(c1,a2)^mult(c2,a1);
        bs x,y;
        if(!div(a,d,x)||!div(b,d,y)) die();
        print(x); print(y);
    }
    else
    {
        if(iszero(a1)&&iszero(b1)) {swap(a1,a2); swap(b1,b2); swap(c1,c2);}
        bs res=mult(c1,b2)^mult(c2,b1);
        if(!iszero(res)) die();
        bs x,y,c;
        bs g=extgcd(a1,b1,x,y);
        if(!div(c1,g,c)) die();
        x=mult(x,c); y=mult(y,c);
        print(x); print(y);
    }
    return 0;
}
