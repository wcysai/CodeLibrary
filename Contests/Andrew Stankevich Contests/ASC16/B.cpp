#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[]=
{
    1,18,4,13,6,10,15,2,17,3,19,16,7,8,11,14,9,12,5,20
};
vector<P> cur;
vector<vector<P> > ans;
void dfs(int now,int left,bool db)
{
    if(now==0)
    {
       if(!db) return; 
       ans.push_back(cur);
       return;
    }
    if(left==0) return;
    if(now>=25)
    {
        cur.push_back(P(25,1));
        dfs(now-25,left-1,false);
        cur.pop_back();
    }
    if(now>=50)
    {
        cur.push_back(P(25,2));
        dfs(now-50,left-1,true);
        cur.pop_back();
    }
    for(int i=0;i<20;i++)
    {
        if(now>=a[i])
        {
            cur.push_back(P(a[i],1));
            dfs(now-a[i],left-1,false);
            cur.pop_back();
        }
        if(now>=a[i]*2)
        {
            cur.push_back(P(a[i],2));
            dfs(now-2*a[i],left-1,true);
            cur.pop_back();
        }
        if(now>=a[i]*3)
        {
            cur.push_back(P(a[i],3));
            dfs(now-3*a[i],left-1,false);
            cur.pop_back();
        }
    }
}
void print(vector<P> &res)
{
    for(auto p:res)
    {
        if(p.F==25&&p.S==1) printf("%d ",25);
        else if(p.F==25) printf("Bull ");
        else if(p.S==1) printf("%d ",p.F);
        else if(p.S==2) printf("D%d ",p.F);
        else printf("T%d ",p.F);
    }
    puts("");
}
int main()
{
    freopen("darts.in","r",stdin);
    freopen("darts.out","w",stdout);
    scanf("%d",&n);
    dfs(n,3,false);
    printf("%d\n",(int)ans.size());
    for(auto p:ans) print(p);
    return 0;
}
