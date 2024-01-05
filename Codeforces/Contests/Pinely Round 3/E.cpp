#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
vector<int> save[MAXN];
bool f[21][21],ff[21];
bool check_valid(int x,int mask){
    memset(ff,false,sizeof(ff));
    for(int i=0;i<x;i++){
        if(mask&(1<<i)){
            for(int j=i+1;j<=x;j+=(i+1)) ff[j]=!ff[j];
        }
    }
    int cnt=0;
    for(int j=1;j<=x;j++) if(ff[j]) cnt++;
    return cnt<=(x/5);
}
bool check(int mask){
    for(int i=0;i<n;i++){
        if(mask&(1<<i)){
            for(int j=0;j<n;j++){
                if((!(mask&(1<<j)))&&f[i+1][j+1]) return false;
            }
        }
    }
    return true;
}
int main(){
    for(int i=5;i<=19;i++){
        for(int j=1;j<(1<<i);j++){
            if(check_valid(i,j)) save[i].push_back(j);
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        if(n>=20){
            for(int i=0;i<m;i++){
                int u,v;
                scanf("%d%d",&u,&v);
            }
            printf("%d\n",n);
            for(int i=1;i<=n;i++) printf("%d%c",i,i==n?'\n':' ');
        }
        else{
            memset(f,false,sizeof(f));
            for(int i=0;i<m;i++){
                int u,v;
                scanf("%d%d",&u,&v);
                f[u][v]=true;
            }
            bool flag=false;
            for(auto mask:save[n]){
                if(check(mask)){
                    vector<int> v;
                    for(int i=0;i<n;i++) if(mask&(1<<i)) v.push_back(i+1);
                    printf("%d\n",(int)v.size());
                    for(auto x:v) printf("%d ",x);
                    printf("\n");
                    flag=true; break;
                }
            }
            if(!flag) puts("-1");
        }
    }
    return 0;
}

