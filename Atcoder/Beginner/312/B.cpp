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
int n,m;
char str[MAXN][MAXN];
bool check(int x,int y){
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(str[x+i-1][y+j-1]!='#') return false;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            if(str[x+i+5][y+j+5]!='#') return false;
    for(int i=1;i<=4;i++) if(str[x+3][y+i-1]!='.') return false;
    for(int i=1;i<=4;i++) if(str[x+i-1][y+3]!='.') return false;
    for(int i=1;i<=4;i++) if(str[x+5][y+i+4]!='.') return false;
    for(int i=1;i<=4;i++) if(str[x+i+4][y+5]!='.') return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i+8<=n;i++)
        for(int j=1;j+8<=m;j++)
            if(check(i,j)) printf("%d %d\n",i,j);
    return 0;
}

