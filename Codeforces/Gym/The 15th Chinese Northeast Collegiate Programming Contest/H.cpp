#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,x,y;
ll k,val;
string str;
void go_down()
{
    assert(x!=n); 
    x++; val=val*2; assert(val<=k*2);
    str+="D";
}
void go_up()
{
    assert(x!=1); assert(val%2==0);
    x--; val=val/2;
    str+="U"; 
}
void go_left()
{
    assert(y!=1); assert(val>=2);
    y--; val=val-2;
    str+="L";
}
void go_right()
{
    assert(y!=n); 
    y++; val=val+2; assert(val<=k*2); 
    str+="R";
}
void increase_by_one()
{
    go_down(); go_left(); go_up(); go_right();
}
void decrease_by_one()
{
    assert(x!=n);
    if(y==n)
    {
        go_left();
        go_down(); go_right(); go_up();
    }
    else
    {
        go_down(); go_right(); go_up(); go_left();
    }
}
int main()
{
    scanf("%d%d",&T,&n);
    while(T--)
    {
        scanf("%lld",&k);
        if(k%2==1) {puts("-1"); continue;}
        str=""; val=1;
        x=1; y=1;
        decrease_by_one();
        go_down(); 
        int fsb=0;
        for(int i=60;i>=1;i--) if((k>>i)&1) {fsb=i; break;}
        int nx=n-fsb;
        while(x<nx) go_down();
        while(y!=n) {go_down(); go_right(); go_up(); if(y!=n) decrease_by_one();}
        bool flag=false;
        assert(n-x==fsb);
        while(x!=n)
        {
            if(((n-x)<=60)&&((k>>(n-x))&1))
            {
                if(flag) increase_by_one();
                else flag=true;
            }
            go_down();
            assert(flag);
        }
        //printf("%d\n",(int)str.size());
        cout<<str<<endl;
    }
}