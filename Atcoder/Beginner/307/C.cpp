#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define y1 dsakda
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int ha,hb,hx,wa,wb,wx;
char pa[MAXN][MAXN],pb[MAXN][MAXN],px[MAXN][MAXN],sheet[MAXN][MAXN];
//start from (11,11)
bool paste(int x1,int y1,int x2,int y2){
    for(int i=1;i<=31;i++)
        for(int j=1;j<=31;j++)
            sheet[i][j]='.';
    for(int i=1;i<=ha;i++)
        for(int j=1;j<=wa;j++){
            if(pa[i][j]!='#') continue;
            int x=x1+i-1,y=y1+j-1;
            if(x<11||x>10+hx||y<11||y>10+wx) return false;
            sheet[x][y]='#';
        }
    for(int i=1;i<=hb;i++)
        for(int j=1;j<=wb;j++){
            if(pb[i][j]!='#') continue;
            int x=x2+i-1,y=y2+j-1;
            if(x<11||x>10+hx||y<11||y>10+wx) return false;
            sheet[x][y]='#';
        }
    for(int i=1;i<=hx;i++)
        for(int j=1;j<=wx;j++)
            if(sheet[10+i][10+j]!=px[i][j]) return false;
    return true;
}
int main()
{
    scanf("%d%d",&ha,&wa);
    for(int i=1;i<=ha;i++) scanf("%s",pa[i]+1);
    scanf("%d%d",&hb,&wb);
    for(int i=1;i<=hb;i++) scanf("%s",pb[i]+1);
    scanf("%d%d",&hx,&wx);
    for(int i=1;i<=hx;i++) scanf("%s",px[i]+1);
    bool f=false;
    for(int x1=1;x1<=21;x1++)
        for(int y1=1;y1<=21;y1++)
            for(int x2=1;x2<=21;x2++)
                for(int y2=1;y2<=21;y2++)
                    if(paste(x1,y1,x2,y2)) f=true;
    if(f) puts("Yes"); else puts("No");
    return 0;
}

