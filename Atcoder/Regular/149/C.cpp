#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
bool used[MAXN*MAXN];
int a[MAXN][MAXN];
bool is_prime[2*MAXN*MAXN];
void sieve()
{
    for(int i=2;i<=2000000;i++) is_prime[i]=true;
    is_prime[1]=false;
    for(int i=2;i<=2000000;i++)
        if(is_prime[i])
            for(int j=2*i;j<=2000000;j+=i) is_prime[j]=false;
}
void print();
bool check()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(j!=n-1&&is_prime[a[i][j]+a[i][j+1]]) return false;
            if(i!=n-1&&is_prime[a[i][j]+a[i+1][j]]) return false;
        }
    return true;
}
void construct_3()
{
    int p[9];
    for(int i=0;i<9;i++) p[i]=i;
    do
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[i][j]=p[i*3+j]+1;
        //print();
        if(check()) break;
    }while(next_permutation(p,p+9));
}
void construct_even(int n)
{
    for(int i=1;i<=n*n;i++) used[i]=false;
    for(int i=0;i<n;i++)
    {
        a[n/2-1][i]=2*i+1; used[2*i+1]=true;
        int x=(i==0?8:2*(2*i+1));
        a[n/2][i]=x; used[x]=true; 
    }
    int now=1;
    for(int i=0;i<n/2-1;i++)
        for(int j=0;j<n;j++)
        {
            while(used[now]) now+=2;
            a[i][j]=now; used[now]=true;
        }
    now=2;
    for(int i=n/2+1;i<n;i++)
        for(int j=0;j<n;j++)
        {
            while(used[now]) now+=2;
            a[i][j]=now; used[now]=true;
        }
}
void construct_odd(int n)
{
    for(int i=1;i<=n*n;i++) used[i]=false;
    a[n/2][n/2]=7; used[7]=true;
    a[n/2+1][n/2]=14; used[14]=true;
    a[n/2-1][n/2+1]=1; used[1]=true;
    a[n/2][n/2+1]=8; used[8]=true;
    int now=3;
    for(int i=n/2+2;i<n;i++)
    {
        while(used[now]) now+=2;
        a[n/2-1][i]=now; used[now]=true;
        a[n/2][i]=now*2; used[now*2]=true;
    }
    for(int i=0;i<n/2;i++)
    {
        while(used[now]) now+=2;
        a[n/2][i]=now; used[now]=true;
        a[n/2+1][i]=now*2; used[now*2]=true;
    }
    int x=0,y=0;
    now=1;
    while(!a[x][y])
    {
        while(used[now]) now+=2;
        a[x][y]=now; used[now]=true;
        y++; if(y==n) {y=0; x++;}
    }
    now=2;
    x=n-1; y=n-1;
    while(!a[x][y])
    {
        while(used[now]) now+=2;
        a[x][y]=now; used[now]=true;
        y--; if(y<0) {y=n-1; x--;}
    }
}
void print()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            printf("%d%c",a[i][j],j==n-1?'\n':' ');
}
int main()
{
    sieve();
    scanf("%d",&n);
    if(n==3) construct_3();
    else if(n%2==0) construct_even(n);
    else construct_odd(n);
    print();
    assert(check());
    return 0;
}

