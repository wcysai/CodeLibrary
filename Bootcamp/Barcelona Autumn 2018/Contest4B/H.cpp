/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-30 19:43:13
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
int N,M,K;
vector<int> boys[MAXN],girls[MAXN];
vector<int> small,large;
bool is_large[MAXN];
bool vis[MAXN];
unordered_map<ll,int> mp; 
void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int main()
{
    read(N);read(M);read(K);   
    for(int i=0;i<K;i++)
    {
        int u,v;
        read(u);read(v);
        boys[u].push_back(v);
        girls[v].push_back(u);
    }
    int B=200;ll ans=0;
    memset(is_large,false,sizeof(is_large));
    for(int i=1;i<=N;i++)
    {
        if((int)boys[i].size()<=B) small.push_back(i);
        else {large.push_back(i); is_large[i]=true;}
    }
    for(int i=0;i<(int)small.size();i++)
    {
        int v=small[i];
        for(int j=0;j<(int)boys[v].size();j++)
            for(int k=j+1;k<(int)boys[v].size();k++)
            {
                int x=boys[v][j],y=boys[v][k];
                if(x>y) swap(x,y);
                ll hash=1LL*x*M+y;
                mp[hash]++;
            }
    }
    for(auto it:mp)
    {
        int k=it.S;
        ans+=1LL*k*(k-1);
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<(int)large.size();i++)
    {
        int v=large[i];
        for(int j=0;j<(int)boys[v].size();j++)
            vis[boys[v][j]]=true;
        for(int j=1;j<=N;j++)
        {
            if(j==v) continue;
            int cnt=0;
            for(int k=0;k<(int)boys[j].size();k++)
                if(vis[boys[j][k]]) cnt++;
            if(is_large[j]) ans+=1LL*cnt*(cnt-1)/2; else ans+=1LL*cnt*(cnt-1);
        }
        for(int j=0;j<(int)boys[v].size();j++)
            vis[boys[v][j]]=false;
    }
    printf("%lld\n",ans/2);
    return 0;
}

