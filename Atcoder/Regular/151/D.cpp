#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[(1<<18)],b[(1<<18)];
int mat[18][2][2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<(1<<n);i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) mat[i][0][0]=mat[i][1][1]=1;
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(mat[x][1-y][0],mat[x][y][0]);
        add(mat[x][1-y][1],mat[x][y][1]);
    }
    for(int i=0;i<n;i++)
    {
        memset(b,0,sizeof(b));
        for(int j=0;j<(1<<n);j++)
        {
            int comp=j^(1<<i);
            if((j>>i)&1)
            {
                add(b[j],1LL*a[j]*mat[i][1][1]%MOD);
                add(b[j],1LL*a[comp]*mat[i][1][0]%MOD);
            }
            else
            {
                add(b[j],1LL*a[j]*mat[i][0][0]%MOD);
                add(b[j],1LL*a[comp]*mat[i][0][1]%MOD);
            }
        }
        swap(a,b);
    }
    for(int i=0;i<(1<<n);i++) printf("%d%c",a[i],i==(1<<n)-1?'\n':' ');
    return 0;
}

