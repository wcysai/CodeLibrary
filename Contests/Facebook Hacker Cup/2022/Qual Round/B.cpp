#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,r,c;
string str[MAXN];
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&r,&c);
        int cnt=0;
        for(int i=0;i<r;i++) cin>>str[i];
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(str[i][j]=='^') cnt++;
        printf("Case #%d:",t);
        if(cnt==0)
        {
            puts("Possible");
            for(int i=0;i<r;i++) cout<<str[i]<<endl;
        }
        else if(r>=2&&c>=2)
        {
            puts("Possible");
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++) printf("^");
                printf("\n");
            }
        }
        else puts("Impossible");
    }
    return 0;
}

