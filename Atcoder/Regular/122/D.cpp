#include<bits/stdc++.h>
#define MAXN 400005
#define MAXM 400005*30
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> v;
int tot,trie[MAXM][2],cnt[MAXM];
void insert(int val,int rt)
{
    cnt[rt]++;
    for(int i=29;i>=0;i--)
    {
        int x=(val>>i)&1;
        if(trie[rt][x]==0) trie[rt][x]=++tot;
        rt=trie[rt][x];
        cnt[rt]++;
    }
}
int find(int val,int rt)
{
    int ans=0;
    for(int i=29;i>=0;i--)
    {
        int x=(val>>i)&1;
        if(trie[rt][x]&&cnt[trie[rt][x]]) 
            rt=trie[rt][x];
        else 
        {
            rt=trie[rt][x^1];
            ans+=(1<<i);
        }
    }
    return ans;
}
void del(int val,int rt)
{
    cnt[rt]--;
    for(int i=29;i>=0;i--)
    {
        int x=(val>>i)&1;
        rt=trie[rt][x];
        cnt[rt]--;
    }
}
int solve(vector<int> &v,int id)
{
    if((int)v.size()==0) return 0;
    if(id<0) return 0;
    vector<int> zero,one;
    for(auto x:v)
    {
        if(x&(1<<id)) one.push_back(x^(1<<id));
        else zero.push_back(x);
    }
    if(one.size()%2==0) 
    {
        return max(solve(one,id-1),solve(zero,id-1));
    }
    else
    {
        tot=1;
        for(auto x:one) insert(x,1);
        int ans=INF;
        for(auto x:zero) ans=min(ans,find(x,1));
        for(auto x:one) del(x,1);
        for(int i=1;i<=tot;i++) trie[i][0]=trie[i][1]=0;
        return ans+(1<<id);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    printf("%d\n",solve(v,29));
    return 0;
}