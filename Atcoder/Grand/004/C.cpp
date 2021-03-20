#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char mp[MAXN][MAXN];
char red[MAXN][MAXN],blue[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            red[i][j]=blue[i][j]='.';
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i&1)
            {
                if(j==0) red[i][j]='#'; else blue[i][j]='#'; 
            }
            else
            {
                if(j==m-1) blue[i][j]='#'; else red[i][j]='#'; 
            }
            if(mp[i][j]=='#') red[i][j]=blue[i][j]='#';
        }
    }
    for(int i=0;i<n;i++) printf("%s\n",red[i]);
    puts("");
    for(int i=0;i<n;i++) printf("%s\n",blue[i]);
    return 0;
}