#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str[MAXN];
int x[MAXN],y[MAXN],type[MAXN];
int rk[MAXN];
bool cmp(int i,int j){
    if(type[i]!=type[j]) return type[i]<type[j];
    if(type[i]==0) return y[i]<y[j];
    if(type[i]==1) return x[i]>x[j];
}
int main(){
    scanf("%d",&n);
    int sumx=0,sumy=0;
    for(int i=1;i<=n;i++){
        cin>>str[i];
        for(int j=0;j<(int)str[i].size();j++){
            if(str[i][j]==')') {
                if(x[i]) x[i]--; else y[i]++;
            }
            else{
                x[i]++;
            }
        }
        sumx+=x[i]; sumy+=y[i];
        if(x[i]>=y[i]) type[i]=0; else type[i]=1;
    }
    if(sumx!=sumy){
        puts("impossible"); return 0;
    }
    for(int i=1;i<=n;i++) rk[i]=i;
    sort(rk+1,rk+n+1,cmp);
    int now=0;
    for(int i=1;i<=n;i++){
        if(now<y[rk[i]]) {puts("impossible"); return 0;}
        now-=y[rk[i]]; now+=x[rk[i]];
    }
    for(int i=1;i<=n;i++) printf("%d\n",rk[i]);
    return 0;
}

