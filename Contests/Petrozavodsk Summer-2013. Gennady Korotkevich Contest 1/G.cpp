#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int n;
int a[MAXN];
vector<int> dis;
vector<int> pos[MAXN];
int main()
{
    freopen("gem.in","r",stdin);
    freopen("gem.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        dis.push_back(a[i]);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=1;i<=n;i++) a[i]=lower_bound(dis.begin(),dis.end(),a[i])-dis.begin()+1;
    int sz=(int)dis.size();
    assert(sz<=300000);
    for(int i=1;i<=n;i++) pos[a[i]].push_back(i);
    int ans=0,st=1,now=1,sum=(int)pos[1].size();
    while(st<=sz)
    {
        while(now<sz&&pos[now+1][0]>pos[now].back())
        {
            now++;
            sum+=(int)pos[now].size();
        }
        int res=0;
        if(now<sz)
        {
            res+=(int)pos[now+1].size();
            for(int i=0;i<(int)pos[now+1].size();i++)
            {
                if(pos[now+1][i]>pos[now].back()) break;
                else res--;
            }
        }
        if(st>1)
        {
            res+=(int)pos[st-1].size();
            for(int i=(int)pos[st-1].size()-1;i>=0;i--)
            {
                if(pos[st-1][i]<pos[st][0]) break;
                else res--;
            }
        }
        ans=max(ans,sum+res);
        st=now+1; now=st; sum=(int)pos[st].size();
    }
    for(int i=1;i<sz;i++)
    {
        int now=0;
        for(int j=0;j<(int)pos[i+1].size();j++)
        {
            while(now<(int)pos[i].size()-1&&pos[i][now+1]<pos[i+1][j]) now++;
            if(pos[i][now]<pos[i+1][j]) ans=max(ans,now+1+(int)pos[i+1].size()-j);
        }
    }
    printf("%d\n",n-ans);
    return 0;
}
