/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-24 23:42:59
 ************************************************************************/

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
int query;
int V,E;
string str;
P a[MAXN];
int strtoi(string x)
{
    int s=0;
    for(int i=x.size()-1;i>=0;i--)
        s=s*10+x[i]-'0';
    return s;
}
int p[MAXN],r[MAXN];
bool used[MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d",&query);
    while(query--)
    {
        scanf("%d%d",&V,&E);
        for(int i=0;i<E;i++)
        {
            cin>>str;
            int id=-1;
            for(int j=0;j<(int)str.size();j++)
            {
                if(str[j]==':')
                {
                    id=j;
                    break;
                }
            }
            int x=strtoi(str.substr(0,id)),y=strtoi(str.substr(id+1,str.size()-id-1));
            a[i].F=x;a[i].S=y;
            //printf("%d %d\n",x,y);
        }
        init(V);
        int t=E,round=1;
        while(true)
        {
            memset(used,false,sizeof(used));
            int cnt=0;
            for(int i=0;i<t;i++)
            {
                int v=find(a[i].F);
                if(!used[v]) {cnt++; used[v]=true;}
                int u=find(a[i].S);
                if(!used[u]) {cnt++; used[u]=true;}
            }
            if(cnt<=2) break;
            int seed=round*32761%t;
            unite(a[seed].F,a[seed].S);
            int now=0;
            while(now<t)
            {
                if(same(a[now].F,a[now].S))
                {
                     for(int i=now+1;i<t;i++)
                        a[i-1]=a[i];
                     t--;
                }
                else now++;
            }
            round++;
        }
        for(int i=0;i<t;i++)
        {
            if(a[i].F>a[i].S) swap(a[i].F,a[i].S);
            printf("%d:%d",a[i].F,a[i].S);
            if(i!=t-1) printf(" ");
        }
        puts("");
    }
    return 0;
}

