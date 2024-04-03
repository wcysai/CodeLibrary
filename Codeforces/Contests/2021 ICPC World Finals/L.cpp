#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXK 10005
#define MAXM 4000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char mp[MAXN][MAXN];
int tot;
map<int,int> trie[1200005];
int cnt[1200005],max_step[1200005],sec_step[1200005];
int save[505][505];
vector<int> v[MAXK];
vector<P> marker;
int num[105][105];
void hardcode(){
    int x=0,y=0,step=0,now=0;
    save[x][y]=now++;
    for(int i=0;i<100;i++){
        step++;
        x--; save[x+150][y+150]=now++;
        for(int j=0;j<step;j++) {y++; save[x+150][y+150]=now++;}
        step++;
        for(int j=0;j<step;j++) {x++; save[x+150][y+150]=now++;}
        for(int j=0;j<step;j++) {y--; save[x+150][y+150]=now++;}
        for(int j=0;j<step;j++) {x--; save[x+150][y+150]=now++;}
    }
}
void construct_str(int id,int x,int y){
    for(auto p:marker){
        v[id].push_back(save[p.F-x+150][p.S-y+150]);
    }
    sort(v[id].begin(),v[id].end());
}
void ins(vector<int> &v){
    int rt=1; cnt[rt]++;
    for(int i=0;i<(int)v.size();i++){
        if(!trie[rt][v[i]]) trie[rt][v[i]]=++tot;
        rt=trie[rt][v[i]];
        cnt[rt]++;
    }
}
int get_res(vector<int> &v){
    int rt=1,cur=0,now=0;
    while(cnt[rt]>1){
        //printf("rt=%d cnt=%d nxt=%d nxtcnt=%d\n",rt,cnt[rt],trie[rt][v[now]],cnt[trie[rt][v[now]]]);
        if(cnt[trie[rt][v[now]]]==1){
            if(v[now]==max_step[rt]) return sec_step[rt]; else return v[now];
        }
        rt=trie[rt][v[now]];
        now++;
    }
    return 0;
}
int main(){
    scanf("%d%d",&m,&n); tot=1;
    hardcode();
   /* for(int i=-5;i<=5;i++){
        for(int j=-5;j<=5;j++) printf("%10d ",save[i+150][j+150]);
        printf("\n");
    }*/
    for(int i=1;i<=n;i++) {
        scanf("%s",mp[i]+1);
        for(int j=1;j<=m;j++) if(mp[i][j]=='X') marker.push_back(P(i,j));
    }
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++){
            construct_str((i-1)*m+j,i,j);
            //for(auto x:v[(i-1)*m+j]) printf("%d ",x);
            //puts("");
            ins(v[(i-1)*m+j]);
        }
    for(int i=1;i<=tot;i++){
        max_step[i]=sec_step[i]=-1;
        vector<int> vec;
        for(auto p:trie[i]){
            if(p.F>max_step[i]){
                sec_step[i]=max_step[i];
                max_step[i]=p.F;
            }
            else if(p.F>sec_step[i]) sec_step[i]=p.F;
        }
    }
    int maxi=0,sum=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            num[i][j]=get_res(v[(i-1)*m+j]);
            //printf("i=%d j=%d num=%d\n",i,j,num[i][j]);
            maxi=max(maxi,num[i][j]);
            sum+=num[i][j];
        }
    printf("%.10f\n",(double)1.0*sum/(n*m));
    printf("%d\n",maxi);
    vector<P> vv;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(num[i][j]==maxi) vv.push_back(P(n-i+1,j));
    sort(vv.begin(),vv.end());
    for(auto p:vv) printf("(%d,%d) ",p.S,p.F);
    printf("\n");
    return 0;
}

