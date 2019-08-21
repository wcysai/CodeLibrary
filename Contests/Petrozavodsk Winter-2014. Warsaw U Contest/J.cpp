#include<bits/stdc++.h>
#define MAXN 3005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN];
int sg[MAXN];
int mex[MAXM];
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=n;i>=1;i--)
    {
        for(int d=1;i+d-1<=n;d++)
        {
            int x=0;
            for(int j=i+d;j<=n;j+=d)
            {
                x^=sg[j];
                mex[x]=i;
            }
        }
        for(int j=1;;j++) if(mex[j]!=i) {sg[i]=j; break;}
    }
    int val=0;
    for(int i=1;i<=n;i++) if(str[i]=='N') val^=sg[i];
    if(val==0) {puts("NIE"); return 0;}
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='N')
        {
            for(int d=1;i+d-1<=n;d++)
            {
                int x=sg[i];
                if(x==val)
                {
                    if(str[i]=='N') str[i]='S'; else str[i]='N';
                    printf("%s",str+1);
                    return 0;
                }
                for(int j=i+d;j<=n;j+=d)
                {
                    x^=sg[j];
                    if(x==val)
                    {
                        for(int k=i;k<=j;k+=d) if(str[k]=='N') str[k]='S'; else str[k]='N';
                        printf("%s",str+1);
                        return 0;
                    }
                }
            }
        }
    }
    assert(0);//shouldn't reach here
}
