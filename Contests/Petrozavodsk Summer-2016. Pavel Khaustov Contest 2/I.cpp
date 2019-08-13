#include<bits/stdc++.h>
#define MAXN 65537
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int a[10][MAXN],rk[10][MAXN];
int inv[10][10];
int bit[MAXN];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
ll get_inversions(int x,int y)
{
    memset(bit,0,sizeof(bit));
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        int pos=rk[y][a[x][i]];
        res+=sum(pos);
        add(pos,1);
    }
    return 1LL*n*(n-1)/2-res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=9;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            rk[i][a[i][j]]=j;
        }
    for(int i=1;i<=9;i++)
        for(int j=i+1;j<=9;j++)
            inv[i][j]=get_inversions(i,j);
    ll ans=INF;
    int id1=-1,id2=-1,id3=-1;
    for(int i=1;i<=9;i++)
        for(int j=i+1;j<=9;j++)
            for(int k=j+1;k<=9;k++)
                if(1LL*n*(n-1)/2-(inv[i][j]+inv[j][k]+inv[i][k])/2<ans)
                {
                    ans=1LL*n*(n-1)/2-(inv[i][j]+inv[j][k]+inv[i][k])/2;
                    id1=i; id2=j; id3=k;
                }
    printf("%d %d %d\n",id1,id2,id3);
    return 0;
}
