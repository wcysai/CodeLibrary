#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN],b[MAXN];
bool row[MAXM],col[MAXM];
int main()
{
    memset(row,false,sizeof(row));
    memset(col,false,sizeof(col));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(row[a[i]])
        {
            puts("0");
            return 0;
        }
        row[a[i]]=true;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        if(col[b[i]])
        {
            puts("0");
            return 0;
        }
        col[b[i]]=true;
    }
    if(!row[n*m]||!col[n*m])
    {
        puts("0");
        return 0;
    }
    int ans=1;
    int c=1,r=1,rem=0;
    for(int i=n*m-1;i>=1;i--)
    {
        if(col[i]&&row[i])
        {
            rem+=c+r;
            c++;r++;
            if(r>n||c>m) {ans=0; break;}
        }
        else if(col[i])
        {
            ans=1LL*r*ans%MOD;
            c++; rem+=r-1;
            if(r>n||c>m) {ans=0; break;}
        }
        else if(row[i])
        {
            ans=1LL*c*ans%MOD;
            r++; rem+=c-1;
            if(r>n||c>m) {ans=0; break;}
        }
        else
        {
            ans=1LL*rem*ans%MOD;
            rem--;
            if(rem<0) {ans=0; break;}
        }
    }
    printf("%d\n",ans);
    return 0;
}

