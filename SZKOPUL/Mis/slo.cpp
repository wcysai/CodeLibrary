#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str[MAXN];
mt19937 wcy(time(NULL));
int rng[150][5];
vector<int> indices[32];
unordered_set<ll> s;
int cnt=0;
ll calc(int x,int y)
{
    if(x>y) swap(x,y);
    return 50000LL*x+y;
}
pair<int,int> recover(ll hash)
{
    int x=hash/50000,y=hash%50000;
    return make_pair(x+1,y+1);
}
void gen()
{
    for(int i=48;i<=122;i++)
        for(int j=0;j<5;j++)
            rng[i][j]=rand()%2;
}
void get_indices()
{
    for(int i=0;i<32;i++) indices[i].clear();
    for(int i=0;i<n;i++)
    {
        int v=0;
        for(int j=0;j<5;j++)
        {
            int x=(int)str[i][j];
            v=v*2+rng[x][j];
        }
        indices[v].push_back(i);
    }
}
void update_ans()
{
    for(int i=0;i<16;i++)
    {
        int j=31-i;
        for(auto x:indices[i])
        {
            for(auto y:indices[j])
            {
                ll res=calc(x,y);
                if(!s.count(res)) 
                {
                    s.insert(res);
                    if((int)s.size()>=100000) return;
                }
            }
        }
    }
}
void solve()
{
    if((int)s.size()>=100000) return;
    gen();
    get_indices();
    update_ans();
}
string ss;
int main()
{
    scanf("%d ",&n);
    for(int i=0;i<n;i++)
    {
        getline(cin,ss);
        for(int j=0;j<(int)ss.size();j++) if(ss[j]>=48&&ss[j]<=122) str[i]+=ss[j];
    }
    for(int i=0;i<450;i++) solve();
    printf("%d\n",(int)s.size());
    for(auto p:s) 
    {
        P pp=recover(p);
        printf("%d %d\n",pp.F,pp.S);
    }
    return 0;
}
