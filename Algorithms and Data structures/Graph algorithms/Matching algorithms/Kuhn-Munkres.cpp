#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
using namespace std;
int w[MAXN][MAXN],x[MAXN],y[MAXN];
int prev_x[MAXN],prev_y[MAXN],son_y[MAXN],slack[MAXN],par[MAXN];
int lx,ly,pop;
void adjust(int v)
{
    son_y[v]=prev_y[v];
    if(prev_x[son_y[v]]!=2)
        adjust(prev_x[son_y[v]]);
}
bool find(int v)
{
    for(int i=0;i<pop;i++)
    {
        if(prev_y[i]==-1)
        {
            if(slack[i]>x[v]+y[i]-w[v][i])
            {
                slack[i]=x[v]+y[i]-w[v][i];
                par[i]=v;
            }
            if(x[v]+y[i]==w[v][i])
            {
                prev_y[i]=v;
                if(son_y[i]==-1)
                {
                    adjust(i);
                    return true;
                }
                if(prev_x[son_y[i]]!=-1)
                    continue;
                prev_x[son_y[i]]=i;
                if(find(son_y[i]))
                    return true;
            }
        }
    }
    return false;
}
int km()
{
    int m;
    for(int i=0;i<pop;i++)
    {
        son_y[i]=-1;
        y[i]=0;
    }
    for(int i=0;i<pop;i++)
    {
        x[i]=0;
        for(int j=0;j<pop;j++)
            x[i]=max(x[i],w[i][j]);
    }
    bool flag;
    for(int i=0;i<pop;i++)
    {
        for(int j=0;j<pop;j++)
        {
            prev_x[j]=prev_y[j]=-1;
            slack[j]=INF;
        }
        prev_x[i]=-2;
        if(find(i)) continue;
        flag=false;
        while(!flag)
        {
            m=INF;
            for(int j=0;j<pop;j++)
                if(prev_y[j]==-1)
                    m=min(m,slack[j]);
            for(int j=0;j<pop;j++)
            {
                if(prev_x[j]!=-1)
                    x[j]-=m;
                if(prev_y[j]!=-1)
                    y[j]+=m;
                else
                    slack[j]-=m;
            }
            for(int j=0;j<pop;j++)
            {
                if(prev_y[j]==-1&&!slack[j])
                {
                    prev_y[j]=par[j];
                    if(son_y[j]==-1)
                    {
                        adjust(j);
                        flag=true;
                        break;
                    }
                    prev_x[son_y[j]]=j;
                    if(find(son_y[j]))
                    {
                        flag=true;
                        break;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<pop;i++)
        ans+=w[son_y[i]][i];
    return ans;
}
int main()
{
    return 0;
}
