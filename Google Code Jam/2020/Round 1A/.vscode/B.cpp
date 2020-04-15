#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
int main()
{
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        scanf("%d",&N);
        printf("Case #%d:\n",_);
        if(N<=30)
        {
            for(int i=1;i<=N;i++) printf("%d %d\n",i,1);
            continue;
        }
        else
        {
            int x=N-30;
            int pos=1;
            int rem=30;
            for(int i=0;i<30;i++)
            {
                if(x&(1<<i))
                {
                    if(pos==0)
                    {
                        for(int j=1;j<=i+1;j++) printf("%d %d\n",i+1,j);
                        pos=1;
                    }
                    else 
                    {
                        for(int j=i+1;j>=1;j--) printf("%d %d\n",i+1,j);
                        pos=0;
                    }
                }
                else
                {
                    rem--;
                    if(pos==0) printf("%d %d\n",i+1,1);
                    else printf("%d %d\n",i+1,i+1);
                }
            }
            if(pos==0)
            {
                for(int i=0;i<rem;i++) printf("%d %d\n",31+i,1);
            }
            else
            {
                for(int i=0;i<rem;i++) printf("%d %d\n",31+i,31+i);
            }
        }
    }
    return 0;
}