#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<queue>
#include<stack>
#include<deque>
#define MAX_MATCH 100
#define MAX_SQUARE 70
#define INF 10005
using namespace std;
int M,S;
int n,k,t,min_res;
bool missing[MAX_MATCH];
bool m[MAX_MATCH][MAX_SQUARE];
int mmax[MAX_SQUARE];
int hstar(int p,vector<bool> state)
{
    vector<pair<int, int> > ps;
    for(int i=0;i<S;i++)
    {
        if(state[i])
        {
            int num=0;
            for(int j=p;j<M;j++)
                if(m[j][i]) num++;
            ps.push_back(make_pair(num,i));
        }
    }
    sort(ps.begin(),ps.end());
    int res=0;
    vector<bool> used(M,false);
    for(int i=0;i<ps.size();i++)
    {
        int id=ps[i].second;
        bool ok=true;
        for(int j=p;j<M;j++)
        {
            if(used[j]&&m[j][id]) ok=false;
        }
        if(ok)
        {
            res++;
            for(int j=p;j<M;j++)
                if(m[j][id]) used[j]=true;
        }
    }
    return res;
}
int dfs(int p,int num,vector<bool> state)
{
    if(p==M) return min_res=num;
    if(num+hstar(p,state)>=min_res) return INF;
    bool use=false, notuse=true;
    for(int i=0;i<S;i++)
    {
        if(state[i]&&m[p][i]) notuse=false;
        if(state[i]&&mmax[i]==p) use=true;
    }
    int res=INF;
    if(!use) res=min(res,dfs(p+1,num,state));
    for(int i=0;i<S;i++)
        if(m[p][i]) state[i]=false;
    if(!notuse) res=min(res,dfs(p+1,num+1,state));
    return res;
}
void solve()
{
    vector<bool> state(S,true);
    for(int i=0;i<S;i++)
    {
        bool broken=false;
        int res=0;
        for(int j=0;j<M;j++)
        {
            if(m[j][i])
            {
                res=j;
                if(missing[j]) broken=true;
            }
        }
        state[i]=!broken;
        mmax[i]=res;
    }
    min_res=0;
    while(dfs(0,0,state)==INF) min_res++;
    printf("%d\n",min_res);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        M=2*n*(n+1);
        S=0;
        for(int i=1;i<=n;i++)
            S+=i*i;
        memset(m,false,sizeof(m));
        memset(missing,false,sizeof(missing));
        int dis=n*2+1,cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<n+1-i;j++)
            {
                for(int k=0;k<n+1-i;k++)
                {
                    int st=j*dis+k;
                    for(int p=0;p<i;p++)
                        m[st+p][cnt]=true;
                    st=st+n;
                    for(int p=0;p<i;p++)
                        m[st+dis*p][cnt]=true;
                    st=st+i;
                    for(int p=0;p<i;p++)
                        m[st+dis*p][cnt]=true;
                    st=st-i-n+i*dis;
                    for(int p=0;p<i;p++)
                        m[st+p][cnt]=true;
                    cnt++;
                }
            }
        }
        scanf("%d",&k);
        int x;
        for(int i=0;i<k;i++)
        {
            scanf("%d",&x);
            missing[x-1]=true;
        }
        solve();
    }
    return 0;
}

