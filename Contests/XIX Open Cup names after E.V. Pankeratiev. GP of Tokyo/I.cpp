#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
bool vis[MAXN][MAXN];
int N,k;
vector<vector<int> >ans;
vector<vector<int> >rev;
void gen()
{
    ans.clear();
    for(int i=0;i<k;i++)
    {
        vector<int> tmp;
        for(int i=0;i<N;i++) tmp.push_back(i);
        random_shuffle(tmp.begin(),tmp.end());
        ans.push_back(tmp);
    }
}
void get_rev()
{
    rev.clear();
    rev.resize(ans.size());
    for(int i=0;i<k;i++)
    {
        rev[i].resize(N);
        for(int j=0;j<N;j++) rev[i][ans[i][j]]=j;
    }
}
vector<int> compose(vector<int> &a,vector<int> &b)
{
    vector<int> c(N);
    for(int i=0;i<N;i++) c[i]=a[b[i]];
    return c;
}
bool check()
{
    memset(vis,false,sizeof(vis));
    vector<int> tmp(N);
    for(int i=0;i<N;i++) tmp[i]=i;
    tmp.resize(N);
    for(int mask=0;mask<(1<<k);mask++)
    {
        for(int i=0;i<N;i++) tmp[i]=i;
        for(int i=0;i<k;i++)
        {
            if(mask&(1<<i)) tmp=compose(ans[i],tmp);
            else tmp=compose(rev[i],tmp);
        }
        for(int i=0;i<N;i++) vis[i][tmp[i]]=true;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(!vis[i][j])
                return false;
    return true;
}
void construct(int n)
{
    ans.clear();
    if(n&1)
    {
        for(int i=0;i<k;i++) 
        {
            vector<int> tmp(N);
            for(int j=0;j<N;j++) tmp[j]=(j+(1<<i))%N;
            ans.push_back(tmp);
        }
    }
    else if(n%4==0)
    {
        for(int i=0;i<k-1;i++) 
        {
            vector<int> tmp(N);
            for(int j=0;j<N;j++) tmp[j]=(j+(1<<i))%N;
            ans.push_back(tmp);
        }
        vector<int> tmp(N);
        for(int i=0;i<N/4;i++)
        {
            tmp[4*i]=4*i+2;
            tmp[4*i+1]=4*i+3;
            tmp[4*i+2]=4*i+1;
            tmp[4*i+3]=4*i;
        }
        ans.push_back(tmp);
    }
    else
    {
        for(int i=0;i<k-2;i++) 
        {
            vector<int> tmp(N);
            for(int j=0;j<N;j++) tmp[j]=(j+(1<<i))%N;
            ans.push_back(tmp);
        }
        vector<int> tmp(N);
        for(int i=0;i<N/4;i++)
        {
            tmp[4*i]=4*i+2;
            tmp[4*i+1]=4*i+3;
            tmp[4*i+2]=4*i+1;
            tmp[4*i+3]=4*i;
        }
        tmp[N-1]=N-1; tmp[N-2]=N-2;
        ans.push_back(tmp);
        tmp.clear(); tmp.resize(N);
        for(int i=0;i<N-4;i++) tmp[i]=i;
        tmp[N-4]=N-2; tmp[N-3]=N-1; tmp[N-2]=N-3; tmp[N-1]=N-4;
        ans.push_back(tmp);
    }
    
}
int main()
{
    srand(time(NULL));
    scanf("%d",&N);
    if(N==2) {puts("-1"); return 0;}
    k=0;
    while((1<<k)<N) k++;
    k++;
    int cnt=0;
    while(true)
    {
        cnt++;
        construct(N);
        get_rev();
        if(check()) break;
    }
    printf("%d\n",k);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<N;j++) printf("%d ",ans[i][j]+1);
        puts("");
    }
}