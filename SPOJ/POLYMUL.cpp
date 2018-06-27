#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
typedef long long ll;
const double PI=acos(-1.0);
struct Complex
{
    double x,y;
    Complex(double _x = 0.0,double _y = 0.0)
    {
        x=_x;
        y=_y;
    }
    Complex operator-(const Complex &b)const
    {
        return Complex(x-b.x,y-b.y);
    }
    Complex operator +(const Complex &b)const
    {
        return Complex(x+b.x,y+b.y);
    }
    Complex operator *(const Complex &b)const
    {
        return Complex(x*b.x-y*b.y,x*b.y+y*b.x);
    }
};
void change(Complex y[],ll len)
{
    ll i,j,k;
    for(i=1,j=len/2;i<len-1;i++)
    {
       if(i<j)swap(y[i],y[j]);
       k = len/2;
       while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k) j+=k;
    }
}
void fft(Complex y[],ll len,ll on)
{
    change(y,len);
    for(ll h=2;h<=len;h<<=1)
    {
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(ll j=0;j<len;j+=h)
        {
            Complex w(1,0);
            for(ll k=j;k<j+h/2;k++)
            {
                Complex u=y[k];
                Complex t=w*y[k+h/2];
                y[k]=u+t;
                y[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)
    for(ll i=0;i<len;i++)
        y[i].x/=len;
}
Complex x1[MAXN],x2[MAXN];
ll a[MAXN],b[MAXN],ans[MAXN];
ll t,n,s;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ll tt=n;
        n++;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(ll i=n-1;i>=0;i--)
            scanf("%lld",&a[i]);
        for(ll i=n-1;i>=0;i--)
            scanf("%lld",&b[i]);
        ll len=1;
        while(len<n*2)
            len<<=1;
        for(ll i=0;i<len;i++)
        {
            x1[i]=Complex((double)a[i],0);
            x2[i]=Complex((double)b[i],0);
        }
        fft(x1,len,1);
        fft(x2,len,1);
        for(ll i=0;i<len;i++)
            x1[i]=x1[i]*x2[i];
        fft(x1,len,-1);
        for(ll i=0;i<=2*tt;i++)
        {
            if(x1[i].x<0) ans[i]=(ll)(-x1[i].x+0.5)*(-1);
            else ans[i]=(ll)(x1[i].x+0.5);
        }
        for(ll i=2*tt;i>=0;i--)
            printf("%lld ",ans[i]);
        puts("");
    }
    return 0;
}
