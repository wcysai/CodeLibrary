#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

__int64 a[1005][105],b[1005][105],inf = 1;

int main()
{
    int n,m,i,j,k;
    for(i = 0;i<18;i++)
    inf*=10;
    while(~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i = 0;i<=m;i++)
        {
            a[0][i] = 1;
        }
        for(j = 1;j<=m;j++)
        {
            for(i = 1;i<=n;i++)
            {
                if(i<j)
                {
                    a[i][j] = a[i][j-1];
                    b[i][j] = b[i][j-1];
                    continue;
                }
                b[i][j] = b[i-j][j]+b[i][j-1]+(a[i-j][j]+a[i][j-1])/inf;//处理大数前面的部位，当超过__int64时，就开始存入b数组，因为__in64是9.22..*10^18次方，下面的式子保证了两个a想加必定不超过__in64
                a[i][j] = (a[i-j][j]+a[i][j-1])%inf;//保留后面的部位
            }
        }
        if(b[n][m])
        printf("%I64d",b[n][m]);
        printf("%I64d\n",a[n][m]);

    }


    return 0;
}