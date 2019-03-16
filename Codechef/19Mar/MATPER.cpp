#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define next dfjosfdj
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,m;
string str;
string p[14];
vector<int> pos[14];
int next[14][MAXN];
vector<int> kmp(string a,string b) // a=pattern, b=text
{
    int n=a.size();
    vector<int> next(n+1,0);
    for(int i=1;i<n;++i)
    {
        int j=i;
        while(j>0)
        {
            j=next[j];
            if(a[j]==a[i])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
    vector<int> p;//p=positions
    int m=b.size();
    for(int i=0,j=0;i<m;++i)
    {
        if(j<n&&b[i]==a[j])
        {
            j++;
        }
        else
        {
            while(j>0)
            {
                j=next[j];
                if(b[i]==a[j])
                {
                    j++;
                    break;
                }
            }
        }
        if(j==n)
        {
            p.push_back(i-n+1);
        }
    }
    return p;
}
unordered_map<int,ll> dp[(1<<14)];
int main()
{
    scanf("%d%d",&n,&m);
    cin>>str;
    for(int i=0;i<m;i++)
    {
        cin>>p[i];
        pos[i]=kmp(p[i],str);
        fill(next[i],next[i]+n+2,INF);
        for(int j=0;j<(int)pos[i].size();j++) pos[i][j]++;
        int now=(int)pos[i].size()-1;
        for(int j=pos[i][now];j>=1;j--)
        {
            while(now>0&&pos[i][now-1]>=j) now--;
            next[i][j]=pos[i][now];
        }
    }
   /* for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d ",next[i][j]);
        puts("");
    }*/
    dp[0][1]=1;
    for(int mask=0;mask<(1<<m);mask++)
    {
        for(auto x:dp[mask])
        {
            //printf("%d %d %lld\n",mask,x.F,x.S);
            for(int i=0;i<m;i++)
            {
                if(mask&(1<<i)) continue;
                if(next[i][x.F]==INF) continue;
                int newmask=mask|(1<<i);
                dp[newmask][next[i][x.F]+(int)p[i].size()]+=x.S;
            }
        }
    }
    ll ans=0;
    for(auto x:dp[(1<<m)-1]) ans+=x.S;
    printf("%lld\n",ans);
    return 0;
}

