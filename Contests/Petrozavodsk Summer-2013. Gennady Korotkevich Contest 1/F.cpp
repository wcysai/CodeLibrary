#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
int main()
{
    freopen("foss.in","r",stdin);
    freopen("foss.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==3)
        {
            puts("1");
            printf("0 0\n1 0\n0 1\n");
            continue;
        }
        if(n%2==0)
        {
            printf("%d\n",(n-4)/2+4);
            printf("0 0\n");
            int id=(n-4)/2+1;
            for(int i=0;i<id;i++) printf("%d %d\n%d %d\n",id-i,i,id-i,i+1);
            printf("%d %d\n",0,id);
        }
        else
        {
            printf("%d\n",(n-4)/2+3);
            printf("0 0\n");
            int id=(n-4)/2+2;
            for(int i=0;i<id-1;i++) printf("%d %d\n%d %d\n",id-i,i,id-i,i+1);
            printf("%d %d\n%d %d\n",1,id-1,0,id);
        }
    }
}
