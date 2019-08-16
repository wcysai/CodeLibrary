#include<bits/stdc++.h>
#define MAXN 2100005
#define INF 1000000000
#define MOD 1000000007
#define REV 500000004
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,M,K;
string str[6];
void FWT(int a[],int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                int x=a[i+j],y=a[i+j+d];
                a[i+j+d]=x+y;
            }
}
void UFWT(int a[],int n)
{
    for(int d=1;d<n;d<<=1)
        for(int m=d<<1,i=0;i<n;i+=m)
            for(int j=0;j<d;j++)
            {
                int x=a[i+j],y=a[i+j+d];
                a[i+j+d]=y-x;
            }
}
void solve(int a[],int b[],int n)
{
    FWT(a,n);
    FWT(b,n);
    for(int i=0;i<n;i++) a[i]=a[i]*b[i];
    UFWT(a,n);
}
int a[MAXN],b[MAXN];
int main()
{
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<M;i++) cin>>str[i];
    for(int i=0;i<K;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for(int j=0;j<(1<<N);j++) a[j]=(int)(str[x][j]-'0');
        for(int j=0;j<(1<<N);j++) b[j]=(int)(str[y][j]-'0');
        solve(a,b,(1<<N));
        for(int j=0;j<(1<<N);j++) printf("%d",a[j]?1:0);
        puts("");
    }
    return 0;
}
