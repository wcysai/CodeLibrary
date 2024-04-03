#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int m,n,q,N,k,a[MAXN];
int type[MAXN],x[MAXN],y[MAXN],z[MAXN],len[MAXN];
int ip[MAXN];//as the input of which node
int op[MAXN];//as the output of which node
vector<int> G[MAXN];
int color[MAXN];
vector<int> order;
void dfs_visit(int v){
	color[v]=1;
	for(int i=0;i<G[v].size();i++){
		int to=G[v][i];
		if(color[to]==0) dfs_visit(to);
	}
	color[v]=2;
	order.push_back(v);
}
void toposort(){
	memset(color,0,sizeof(color));
	for(int i=1;i<=N;i++)
		if(color[i]==0)
			dfs_visit(i);
}
int solve(int i,int k){
    if(len[i]<k) return -1;
    if(i==1) return k;
    int id=op[i];
    if(type[id]==0){
        int mini=min(len[x[id]],len[y[id]]);
        if(k<=2*mini){
            if(k&1) return solve(x[id],(k+1)/2);
            else return solve(y[id],k/2);
        }
        else{
            if(len[x[id]]>len[y[id]]) return solve(x[id],k-mini);
            else return solve(y[id],k-mini);
        }
    }
    else{
        if(y[id]==i) return solve(x[id],2*k-1);
        else return solve(x[id],2*k);
    }
}
int main(){
    scanf("%d%d%d",&m,&n,&q);
    N=1;
    for(int i=1;i<=n;i++){
        string str;
        int a,b,c;
        cin>>str;
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        N=max(N,x[i]); N=max(N,y[i]); N=max(N,z[i]);
        if(str[0]=='M') {
            type[i]=0; op[z[i]]=i;
            G[x[i]].push_back(z[i]); G[y[i]].push_back(z[i]);
        }
        else{
            type[i]=1; op[y[i]]=op[z[i]]=i;
            G[x[i]].push_back(y[i]); G[x[i]].push_back(z[i]);
        }
    }
    toposort();
    reverse(order.begin(),order.end());
    len[1]=m;
    for(auto i:order){
        if(i==1) continue;
        int id=op[i];
        if(type[id]==0){
            len[i]=len[x[id]]+len[y[id]];
        }
        else if(i==y[id]) len[i]=(len[x[id]]+1)/2;
        else len[i]=len[x[id]]/2;
    }
    for(int i=0;i<q;i++){
        int x,k;
        scanf("%d%d",&x,&k);
        int res=solve(x,k);
        if(res==-1) puts("none"); else printf("%d\n",res);
    }
    return 0;
}

