/*************************************************************************
    > File Name: BINSTR.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-11 01:18:26
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,q,tot,pos[MAXN];
vector<char> str[MAXN];
char ch[MAXN];
P a[MAXN];
struct trie
{
    vector<map<int,int> > mp;
    vector<int> sz;
    vector<int> minx;
    int maxlen;
    int tot;
    void init()
    {
        mp.clear();sz.clear();minx.clear();
        map<int,int> newmp;newmp.clear();mp.push_back(newmp);
        sz.push_back(0);minx.push_back(INF);
    }
    int newnode()
    {
        ++tot;
        map<int,int> newmp;newmp.clear();mp.push_back(newmp);
        sz.push_back(0);
        minx.push_back(INF);
        return tot;
    }
    void insert(char *s,int id)
    {
        int len=strlen(s);
        int rt=0;
        sz[rt]++;minx[rt]=min(minx[rt],id);
        int now=1000001-len;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='1')
            {
                if(!mp[rt][now]) mp[rt][now]=newnode();
                rt=mp[rt][now];
                sz[rt]++;minx[rt]=min(minx[rt],id);
            }
            now++;
        }
    }
};
struct segtrie
{
    trie tr[4*MAXN];
    vector<int> rg;
    void build(int k,int l,int r)
    {
        tr[k].init();
        if(l==r) {pos[l]=k; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid);build(k*2+1,mid+1,r);
    }
    void update(int k,char *s)
    {
        int id=k;
        k=pos[k];
        while(k>1)
        {
            tr[k].insert(s,id);
            k=k/2;
        }
    }
    void sep(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return;
        if(l>=x&&r<=y) {rg.push_back(k); return;}
        int mid=(l+r)/2;
        sep(k*2,l,mid,x,y);sep(k*2+1,mid+1,r,x,y);
    }
    int query(int x,int y,char *s)
    {
        rg.clear();
        sep(1,1,n,x,y);
        int ans=INF,sum=0;
        vector<int> v((int)rg.size(),0);
        int len=strlen(s),z=1000001-len;
        while(true)
        {
            for(int i=0;i<(int)rg.size();i++) if(v[i]!=-1) sum+=tr[rg[i]].sz[v[i]];
            int now=INF;
            for(int i=0;i<(int)rg.size();i++)
                for(auto it:tr[rg[i]].mp[v[i]])
                    if(it.F<=z||s[it.F-z]=='0') now=min(now,it.F); 
            ans=INF;
            for(int i=0;i<(int)rg.size();i++)
            {
                if(v[i]!=-1)
                {
                    if(tr[rg[i]].mp[v[i]][now]) {v[i]=tr[rg[i]].mp[v[i]][now]; ans=min(ans,tr[rg[i]].minx[v[i]]);} 
                    else v[i]=-1;
                }
            }
            if(now==INF) return ans;
            if(sum==1) return ans;
        }
        return ans;
    }
}seg;
int main()
{
    scanf("%d%d",&n,&q);
    seg.build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ch);
        seg.update(i,ch);
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        scanf("%s",ch);
        printf("%d\n",seg.query(l,r,ch));
    }
    return 0;
}

