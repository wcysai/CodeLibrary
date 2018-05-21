#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define INF 1000000000
using namespace std;
char s[100];
int x,y;
int m,n;
int pow10(int x)
{
    int res=1;
    for(int i=1;i<=x;i++)
        res*=10;
    return res;
}
int gcd(int x,int y)
{
    if(y==0) return x;
    else return gcd(y,x%y);
}
void solve(int x,int y,int len)
{
    int deno,nume,dummy;
    deno=pow10(y-x+1)-pow10(y-x+1-len);
    int left,right;
    left=x;
    right=y;
    nume=0;
    dummy=0;
    while(left<=right-len)
    {
        nume*=10;
        nume+=s[left]-48;
        dummy*=10;
        dummy+=s[left]-48;
        left++;
    }
        while(left<=right)
    {
        nume*=10;
        nume+=s[left]-48;
        left++;
    }
    nume-=dummy;
    int k=gcd(nume,deno);
    nume/=k;
    deno/=k;
    if(deno<n)
    {
        m=nume;
        n=deno;
    }
    return;
}
int main()
{
    scanf("%s",&s);
    while(strlen(s)>1)
    {
    x=2;
    y=strlen(s)-4;
    m=INF;
    n=INF;
    for(int i=1;i<=y-x+1;i++)
      solve(x,y,i);
    printf("%d/%d\n",m,n);
        scanf("%s",&s);
    }
    return 0;
}
