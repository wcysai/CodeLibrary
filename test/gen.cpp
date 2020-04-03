#include<bits/stdc++.h>
#define MAXN 1200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,y;
double p[MAXN];
mt19937 wcy(time(NULL));
vector<int> G[MAXN];
double sample()
{
    int x=wcy()%1000000000;
    return (double)x/(double)(INF);
}
double sample2()
{
    int x=wcy()%10000000;
    return (double)x/(double)(INF);
}
int main()
{
    n=20;
    for(int i=1;i<(1<<20);i++) p[i]=sample2();
    for(int i=0;i<(1<<20);i++)
    {
        for(int j=0;j<20;j++)
        {
            int x=wcy()%(1<<20);
            if(x==i) continue;
            G[i].push_back(x);
            G[x].push_back(i);
        }
    }
    p[0]=1;
    int now=0;
    for(int i=0;i<20;i++)
    {
        int sz=(int)G[now].size();
        int id=wcy()%sz;
        int to=G[now][id];
        double prob=p[now]/(p[now]+p[id]);
        printf("prob=%f\n",prob);
        if(sample()>prob) now=id; 
    }
    printf("%.10f\n",p[now]);
    return 0;
}