#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p,a[MAXN];
vector<int> G[MAXN];
int main(){
    scanf("%d%d",&n,&p);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    int num=0;
    for(int i=0;i<n;i++) if(G[i].size()==1) num++;
    if(p%num==0) printf("%d\n",2*(p/num));
    else if(p%num==1) printf("%d\n",2*(p/num)+1);
    else printf("%d\n",2*(p/num)+2);
    return 0;
}

