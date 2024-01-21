#include<bits/stdc++.h>
#define MAXN 100005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,m,q,a[MAXN],b[MAXN];
int l[MAXLOGN][MAXN],r[MAXLOGN][MAXN];
vector<P> op[2][MAXN];
int stl[MAXLOGN][MAXLOGN][MAXN],str[MAXLOGN][MAXLOGN][MAXN];
int pre[MAXN];
void init(int n){
    pre[1]=0;
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
}
void build(int k){
    for(int i=n;i>=1;--i){
        stl[k][0][i]=l[k][i];
        for(int j=1;(i+(1<<j)-1)<=n;++j){
            stl[k][j][i]=min(stl[k][j-1][i],stl[k][j-1][i+(1<<j-1)]);
           // printf("k=%d j=%d i=%d stl=%d\n",k,j,i,stl[k][j][i]);
        }
    }
    for(int i=n;i>=1;--i){
        str[k][0][i]=r[k][i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            str[k][j][i]=max(str[k][j-1][i],str[k][j-1][i+(1<<j-1)]);
    }
}
int queryl(int k,int l,int r){
    int len=r-l+1,t=pre[len];
   // printf("l=%d r=%d t=%d\n",l,r,t);
    return min(stl[k][t][l],stl[k][t][r-(1<<t)+1]);
}
int queryr(int k,int l,int r){
    int len=r-l+1,t=pre[len];
    return max(str[k][t][l],str[k][t][r-(1<<t)+1]);
}
int query(int l,int r){
    int curl=l,curr=l,ans=0;
    for(int i=MAXLOGN-1;i>=0;i--){
        int newl=queryl(i,curl,curr),newr=queryr(i,curl,curr);
        if(r>=newl&&r<=newr); else {
            ans+=(1<<i);
            curl=newl; curr=newr;
        }
    }
    int nxtl=queryl(0,curl,curr),nxtr=queryr(0,curl,curr);
    if(r>=nxtl&&r<=nxtr) return ans+1; else return -1;
}
int main(){
    scanf("%d%d%d",&n,&k,&m);
    for(int i=0;i<m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l<r){
            op[0][l].push_back(P(r,1));
            op[0][min(r+1,l+k)].push_back(P(r,-1));
        }
        else{
            op[1][l].push_back(P(r,1));
            op[1][max(r-1,l-k)].push_back(P(r,-1));
        }
    }
    init(n);
    multiset<int> s;
    for(int i=1;i<=n;i++){
        for(auto p:op[0][i]) if(p.S==1) s.insert(p.F); else s.erase(s.find(p.F));
        if(!s.size()) r[0][i]=i; else r[0][i]=*(--s.end());
       // printf("i=%d r=%d\n",i,r[0][i]);
    }
    s.clear();
    for(int i=n;i>=1;i--){
        for(auto p:op[1][i]) if(p.S==1) s.insert(p.F); else s.erase(s.find(p.F));
        if(!s.size()) l[0][i]=i; else l[0][i]=*s.begin();
     //   printf("i=%d l=%d\n",i,l[0][i]);
    }
    for(int i=0;i+1<MAXLOGN;i++){
        build(i);
        for(int j=1;j<=n;j++){
            l[i+1][j]=queryl(i,l[i][j],r[i][j]);
            r[i+1][j]=queryr(i,l[i][j],r[i][j]);
        //    printf("i=%d j=%d l=%d r=%d\n",i,j,l[i][j],r[i][j]);
        }
    }
    build(MAXLOGN-1);
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }
    return 0;
}

