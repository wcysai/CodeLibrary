#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,c[MAXN],cnt[MAXN],b[MAXN];
int t,tot;
vector<int> v;
bool cmp(int x,int y)
{
    return cnt[x]>cnt[y];
}
void go(int x)
{
    if(cnt[v[x]]==1) return;
    if(x==(int)v.size()-1||cnt[v[x+1]]==1) {for(int i=0;i<cnt[v[x]];i++) b[++tot]=v[x]; return;}
    b[++tot]=v[x];
    go(x+1);
    for(int i=0;i<cnt[v[x]]-1;i++) b[++tot]=v[x];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt[i]=0;
        v.clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&c[i]);
            cnt[c[i]]++;
            if(cnt[c[i]]==1) v.push_back(c[i]);
        }
        sort(v.begin(),v.end(),cmp);
        int x=2;
        vector<int> single;
        for(int i=0;i<(int)v.size();i++) 
        {
            x+=(cnt[v[i]]-2);
            if(cnt[v[i]]==1) single.push_back(v[i]);
        }
        if(x<0) 
        {
            for(int i=0;i<(int)v.size();i++)
                for(int j=0;j<cnt[v[i]];j++)
                    printf("%d ",v[i]); 
            printf("\n");
            continue;
        }
        tot=0;
        go(0);
        for(int i=1;i<=tot;i++)
        {
            printf("%d ",b[i]);
            if(single.size())
            {
                if(i==tot||b[i]==b[i+1]) {printf("%d ",single.back()); single.pop_back();}
            }
        }
        printf("\n");
    }
    return 0;
}

