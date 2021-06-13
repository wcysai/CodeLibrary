#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll fib[MAXN];
ll n,x,y;
vector<int> v;
void addx()
{
    x++; v.push_back(1);
}
void addy()
{
    y++; v.push_back(2);
}
void addxy()
{
    x+=y; v.push_back(3);
}
void addyx()
{
    y+=x; v.push_back(4);
}
void addone()
{
    addx(); if(x%2==0) addy();
}
int main()
{
    scanf("%lld",&n);
    if(n==1)
    {
        printf("1\n1\n");
        return 0;
    }
    fib[1]=1; fib[2]=1;
    int now;
    for(int i=3;;i++) 
    {
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i]>=n) {now=i; break;}
    }
    for(int i=now;i>=1;i--)
    {
        while(n>=fib[i])
        {
            if(i&1) addx(); else addy();
            n-=fib[i];
        }
        if(i==1) break;
        if(i&1) addyx();
        else addxy();
    }
    printf("%d\n",(int)v.size());
    for(auto p:v) printf("%d\n",p);
    return 0;
}