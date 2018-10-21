/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-20 18:35:53
 ************************************************************************/

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
int n,m,s[MAXN],h[MAXN],a[MAXN],sum[MAXN];
int minx[MAXN][MAXN];
vector<P> l,r;
vector<int> movel,mover;
bool solvel(int dest,bool visdest,bool p)
{
    if(l.size()==0) 
    {
        if(!visdest) return true;
        return false;
    }
    for(int i=0;i<(int)l.size();i++)
    {
        int v=l[i].S,rem;
        assert(a[l[i].F]==0);
        if(visdest) rem=h[v]+minx[l[i].F][dest];
        else 
        {
            if(l[i].F==dest) rem=h[v];
            else rem=h[v]+minx[l[i].F][dest-1];
        }
        if(rem>=0) 
        {
            if(p)
            {
                movel.push_back(l[i].S);
                for(int j=i-1;j>=0;j--) movel.push_back(l[j].S);
                for(int j=i+1;j<(int)l.size();j++) movel.push_back(l[j].S);
            }
            return true;
        }
        else
        {
            if(i==(int)l.size()-1) return false;
            if(minx[l[i].F][l[i+1].F]+h[v]<0) return false;
        }
    }
    return true;
}
bool solver(int dest,bool visdest,bool p)
{
    if(r.size()==0) 
    {
        if(!visdest) return true;
        return false;
    }
    for(int i=(int)r.size()-1;i>=0;i--)
    {
        int v=r[i].S,rem;
        assert(a[r[i].F]==0);
        if(visdest) rem=h[v]+minx[r[i].F][dest];
        else rem=h[v]+minx[r[i].F][dest+1];
        if(rem>=0) 
        {
            if(p)
            {
                mover.push_back(r[i].S);
                for(int j=i+1;j<(int)r.size();j++) mover.push_back(r[j].S);
                for(int j=i-1;j>=0;j--) mover.push_back(r[j].S);
            }
            return true;
        }
        else
        {
            if(i==0) return false;
            if(minx[r[i].F][r[i-1].F]+h[v]<0) return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&s[i],&h[i]);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++)
        {
            if(i==j) minx[i][j]=min(0,a[i]);
            else if(i<j)
            {
                int cur=0;
                for(int k=i;k<=j;k++)
                {
                    cur+=a[k];
                    minx[i][j]=min(minx[i][j],cur);
                }
            }
            else
            {
                int cur=0;
                for(int k=i;k>=j;k--)
                {
                    cur+=a[k];
                    minx[i][j]=min(minx[i][j],cur);
                }
            }
        }
    for(int i=1;i<=n;i++)
    {
        l.clear();r.clear();
        for(int j=1;j<=m;j++) if(s[j]<=i) l.push_back(P(s[j],j)); else r.push_back(P(s[j],j));
        sort(l.begin(),l.end());sort(r.begin(),r.end());
        //for(auto it:l) printf("l %d %d\n",it.F,it.S);
        //for(auto it:r) printf("r %d %d\n",it.F,it.S);
        if(solvel(i,true,false)&&solver(i,false,false))
        {
            printf("%d\n",i);
            solvel(i,true,true);solver(i,false,true);
            for(auto it:movel) printf("%d ",it);
            for(auto it:mover) printf("%d ",it);
            return 0;
        }
        if(solvel(i,false,false)&&solver(i,true,false))
        {
            printf("%d\n",i);
            solvel(i,false,true);solver(i,true,true);
            for(auto it:mover) printf("%d ",it);
            for(auto it:movel) printf("%d ",it);
            return 0;
        }
    }
    puts("-1");
    return 0;
}

