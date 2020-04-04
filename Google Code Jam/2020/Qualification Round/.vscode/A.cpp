#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN][MAXN];
bool has[MAXN];
int main()
{
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        int trace=0,row=0,col=0;
        for(int i=1;i<=n;i++) trace+=a[i][i];
        for(int i=1;i<=n;i++)
        {
            memset(has,false,sizeof(has));
            for(int j=1;j<=n;j++) has[a[i][j]]=true;
            bool f=true;
            for(int j=1;j<=n;j++) if(!has[j]) f=false;
            if(!f) row++;
        }
        for(int i=1;i<=n;i++)
        {
            memset(has,false,sizeof(has));
            for(int j=1;j<=n;j++) has[a[j][i]]=true;
            bool f=true;
            for(int j=1;j<=n;j++) if(!has[j]) f=false;
            if(!f) col++;
        }
        printf("Case #%d: %d %d %d\n",_,trace,row,col);
    }
    return 0;
}