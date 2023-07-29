#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
char str[MAXN];
int sufmin[MAXN][2][2],premax[MAXN][2][2];//curpos,A/B,even/odd
P suflast[MAXN][2][2],prelast[MAXN][2][2];
char ans[MAXN];
void chmin(int i,int j,int x,int y,int cost){
    if(sufmin[i+1][y][(x+cost)&1]+cost<sufmin[i][j][x]){
        sufmin[i][j][x]=sufmin[i+1][y][(x+cost)&1]+cost;
        suflast[i][j][x]=P(y,(x+cost)&1);
    }
}
void chmax(int i,int j,int x,int y,int cost){
    if(premax[i-1][y][(x+cost)&1]+cost>premax[i][j][x]){
        premax[i][j][x]=premax[i-1][y][(x+cost)&1]+cost;
        prelast[i][j][x]=P(y,(x+cost)&1);
    }
}
void construct(int pos,int prech,int prepar,int sufch,int sufpar){
    //printf("pos=%d i=%d j=%d x=%d y=%d\n",pos,prech,prepar,sufch,sufpar);
    puts("YES");
    int now=pos,x=prech,y=prepar;
    while(now>=1){
        ans[now]='A'+x;
        P p=prelast[now][x][y];
        x=p.F; y=p.S; now--;
    }
    now=pos+1,x=sufch,y=sufpar;
    while(now<=n){
        ans[now]='A'+y;
        P p=suflast[now][x][y];
        x=p.F; y=p.S; now++;
    }
    for(int i=1;i<=n;i++) printf("%c",ans[i]);
    printf("\n");
    return;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        scanf("%s",str+1);
        for(int i=2;i<=n;i++) if(str[i]!=str[i-1]) k--;
        if(k<0) {puts("NO"); continue;}
        for(int i=0;i<=n;i++)
            for(int j=0;j<2;j++)
                for(int x=0;x<2;x++){
                    sufmin[i][j][x]=INF; premax[i][j][x]=-INF;
                }
        for(int i=0;i<2;i++){
            if(str[n]=='A'+i){
                sufmin[n][i][0]=0;
                sufmin[n][i][1]=INF;
            }
            else{
                sufmin[n][i][1]=1;
                sufmin[n][i][0]=INF;
            }
        }
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<2;j++)
                for(int x=0;x<2;x++){
                    for(int y=0;y<2;y++){
                        int cost=(str[i]!='A'+j?1:0)+(j!=y?1:0);
                        chmin(i,j,x,y,cost);
                    }
                }
        }
        for(int i=0;i<2;i++){
            if(str[1]=='A'+i){
                premax[1][i][0]=0;
                premax[1][i][1]=-INF;
            }
            else{
                premax[1][i][1]=1;
                premax[1][i][0]=-INF;
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=0;j<2;j++)
                for(int x=0;x<2;x++){
                    for(int y=0;y<2;y++){
                        int cost=(str[i]!='A'+j?1:0)+(j!=y?1:0);
                        chmax(i,j,x,y,cost);
                    }
                }
        }
        bool f=true;
        for(int i=0;i<2;i++){
            if(!f) break;
            for(int j=0;j<2;j++){
                //printf("i=%d j=%d suf=%d\n",i,j,sufmin[1][i][j]);
                if(sufmin[1][i][j]==k){
                    construct(0,i,j,i,j);
                    f=false; break;
                }
            }
        }
        for(int i=0;i<2;i++){
            if(!f) break;
            for(int j=0;j<2;j++){
                if(premax[n][i][j]==k){
                    construct(n,i,j,i,j);
                    f=false; break;
                }
            }
        }
        //printf("k=%d\n",k);
        for(int pos=1;pos<=n-1;pos++){
            if(!f) break;
            for(int i=0;i<2;i++){
                if(!f) break;
                for(int j=0;j<2;j++){
                    if(!f) break;
                    for(int x=0;x<2;x++){
                        if(!f) break;
                        for(int y=0;y<2;y++){
                            //printf("pos=%d i=%d j=%d x=%d y=%d pre=%d suf=%d\n",pos,i,j,x,y,premax[pos][i][j],sufmin[pos+1][x][y]);
                            if(premax[pos][i][j]+sufmin[pos+1][x][y]+(i!=x?1:0)==k){
                                construct(pos,i,j,x,y);
                                f=false; break;
                            }
                        }
                    }
                }
            }
        }
        if(f) puts("NO"); 
    }
    return 0;
}

