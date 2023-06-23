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
int t,n,k,a[MAXN];
vector<int> L,R;
int dp[MAXN][2][2][2][2];//0: less 1: 
int solve(int now,int xless,int xgr,int yless,int ygr){
    int &res=dp[now][xless][xgr][yless][ygr];
    if(res!=-1) return res; 
    if(now==100) return 0;
    int xlow=xgr?0:L[now],xhigh=xless?9:R[now];
    int ylow=ygr?0:L[now],yhigh=yless?9:R[now];
    for(int x=xlow;x<=xhigh;x++){
        for(int y=ylow;y<=yhigh;y++){
            res=max(res,max(x-y,y-x)+solve(now+1,xless||(x<R[now]),xgr||(x>L[now]),yless||(y<R[now]),ygr||(y>L[now])));
        }
    }
    return res;
}
void read(vector<int> &A){
    A.clear();
    string str; cin>>str;
    int sz=(int)str.size();
    for(int i=0;i<100-sz;i++) A.push_back(0);
    for(int i=0;i<(int)str.size();i++) A.push_back(str[i]-'0');
}
int main()
{
    scanf("%d",&t);
    while(t--){
        read(L); read(R);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(0,0,0,0,0));
    }
    return 0;
}

