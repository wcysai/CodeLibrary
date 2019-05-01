#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 40
#define INF 1000000000
#define MOD 1000000007
#define BASE 19260817
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
typedef unsigned long long ull;
int n,t,p,tot;
VI st,ed;
int m[MAXN],l[MAXN];
ull get_hash(vector<int> &v)
{
    ull x=0;
    for(int i=0;i<(int)v.size();i++) x=x*BASE+v[i]+1;
    return x;
}
unordered_map<ull,int> mp;
void permute(VI &v,int m,int l)
{
    rotate(v.begin(),v.begin()+n-m-l,v.begin()+n-m);
}
void inverse_permute(VI &v,int m,int l)
{
    permute(v,m,n-m-l);
}
void dfs(int steps,int mask)
{
    if(steps==0)
    {
        mp[get_hash(st)]=mask;
        return;
    }
    for(int i=0;i<p;i++)
    {
        permute(st,m[i],l[i]);
        dfs(steps-1,mask*p+i);
        inverse_permute(st,m[i],l[i]);
    }
}
void rdfs(int steps,int mask)
{
    if(steps==0)
    {
        tot++; 
        if(mp.find(get_hash(ed))!=mp.end())
        {
            int nmask=mp[get_hash(ed)];
            vector<int> ans;
            for(int i=0;i<t/2;i++)
            {
                ans.push_back(nmask%p);
                nmask/=p;
            }
            reverse(ans.begin(),ans.end());

            for(int i=0;i<(t+1)/2;i++)
            {
                ans.push_back(mask%p);
                mask/=p;
            }
            for(auto x:ans) printf("%d ",x+1);
            exit(0);
        }
        else return;
    }
    for(int i=0;i<p;i++)
    {
        inverse_permute(ed,m[i],l[i]);
        rdfs(steps-1,mask*p+i);
        permute(ed,m[i],l[i]);
    }
}
int main()
{
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    scanf("%d%d%d",&n,&t,&p);
    st.resize(n); ed.resize(n);
    for(int i=0;i<n;i++) 
    {
        int x;
        scanf("%d",&x);
        st[i]=x-1;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        ed[i]=x-1;
    }
    for(int i=0;i<p;i++) scanf("%d%d",&m[i],&l[i]);
    dfs(t/2,0); rdfs((t+1)/2,0);
    puts("Impossible");
    return 0;
}
