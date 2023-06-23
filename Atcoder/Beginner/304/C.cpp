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
int n,d,x[MAXN],y[MAXN];
bool inf[MAXN];
int main()
{
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    queue<int> que;
    inf[1]=true; que.push(1);
    while(que.size()){
        int v=que.front(); que.pop(); 
        for(int i=1;i<=n;i++){
            if(inf[i]) continue;
            if(1LL*(x[i]-x[v])*(x[i]-x[v])+1LL*(y[i]-y[v])*(y[i]-y[v])<=1LL*d*d){
                inf[i]=true;
                que.push(i);
            }
        }
    }
    for(int i=1;i<=n;i++) if(inf[i]) puts("Yes"); else puts("No");
    return 0;
}

