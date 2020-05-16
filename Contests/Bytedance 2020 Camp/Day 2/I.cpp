#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 20
#define INF 1000000
#define MOD 1000000007
#define F first
#define S second
#define __int128 long long
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,p,q,n,a,b;
P save[105][105];
void solve(int l1,int r1,int l2,int r2)
{
    if(r1+r2>INF)
    {
        a=l1; b=r1;
        return;
    }
    int x=l1+l2,y=r1+r2;
    // x^2q>=y^2p
    __int128 xx=1LL*x*x,yy=1LL*y*y;
    xx=xx*q; yy=yy*p;
    if(xx>yy) solve(l1,r1,x,y); else solve(x,y,l2,r2);
}
// f:\sum_{i=0}^{n}\lfloor\frac{ai+b}{c}\rfloor
// g:\sum_{i=0}^{n}i\times\lfloor\frac{ai+b}{c}\rfloor
// h:\sum_{i=0}^{n}\lfloor\frac{ai+b}{c}\rfloor^{2}
__int128 cal(__int128 a,__int128 b,__int128 c,ll n)
{
    if(!a) return 0;
    __int128 x,y;
    if(a>=c||b>=c)
    {
        x=cal(a%c,b%c,c,n);
        y=a/c*n*(n+1)/2+b/c*(n+1)+x;
        return y;
    }
    __int128 m=(a*n+b)/c;
    x=cal(c,c-b-1,a,m-1);
    y=n*m-x;
    return y;
}
void print(__int128 x)
{
	if (!x) return ;
	if (x < 0) putchar('-'),x = -x;
	print(x / 10);
	putchar(x % 10 + '0');
}
int main()
{
    clock_t startTime,endTime;
    startTime = clock();//计时开始
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
        {
            p=i;
            q=j;
            solve(0,1,1,0);
            save[i][j]=P(a,b); 
        }
    endTime = clock();//计时结束
    cout << "The run time is: " <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&p,&q,&n);
        a=save[p][q].F; b=save[p][q].S;
        __int128 x=cal(a,0,b,n);
        x+=n+1;
        print(x);
        printf("\n");
    }
}