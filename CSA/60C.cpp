#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
int n,k,m;
vector<int> G[MAXN];
int ind[MAXN],outd[MAXN];
bool valid[MAXN];
int perm[MAXN],used[MAXN];
int ti=0;
vector<int> zeroind;
int main()
{
    scanf("%d%d%d",&n,&k,&m);
    mat a(n,vec(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<k;i++)
        G[i].clear();
    memset(ind,0,sizeof(ind));
    memset(outd,0,sizeof(outd));
    memset(valid,true,sizeof(valid));
    memset(perm,-1,sizeof(perm));
    bool f;
    for(int i=0;i<n;i++)
        valid[a[i][0]]=false;
    for(int i=1;i<n;i++)
    {
        f=false;
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!=a[i-1][j])
            {
                G[a[i-1][j]].push_back(a[i][j]);
                ind[a[i][j]]++;
                outd[a[i-1][j]]++;
                f=true;
                break;
            }
        }
        if(!f) break;
    }
    if(!f)
    {
        printf("-1\n");
        return 0;
    }
    f=false;
    int t=0;
    for(int i=0;i<k;i++)
        if(valid[i]&&ind[i]==0)
        {
            f=true;
            t=i;
            break;
        }
    if(!f)
    {
        printf("-1\n");
        return 0;
    }
    zeroind.push_back(t);
    for(int i=0;i<k;i++)
        if(ind[i]==0&&i!=t) zeroind.push_back(i);
    for(int i=0;i<zeroind.size();i++)
    {
        int p=zeroind[i];
        used[p]=true;
        perm[p]=ti;
        ti++;
        for(int j=0;j<G[p].size();j++)
        {
            ind[G[p][j]]--;
            if(ind[G[p][j]]==0) zeroind.push_back(G[p][j]);
        }
    }
    if(ti<k)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<k;i++)
        printf("%d ",perm[i]);
    return 0;
}

