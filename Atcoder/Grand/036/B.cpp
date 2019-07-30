#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,a[MAXN];
int tobe[MAXN];
bool has[MAXN];
ll K;
vector<int> v,ans;
int main()
{
    scanf("%d%lld",&N,&K);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    for(int i=1;i<=200000;i++) tobe[i]=i;
    for(int i=1;i<=N;i++) swap(tobe[0],tobe[a[i]]);
    int now=0,tot=0;
    do
    {
        now=tobe[now];
        v.push_back(now);
        tot++;
    }while(now!=0);
    reverse(v.begin(),v.end());
    K=K%(int)v.size();
    int x=v[K];
    if(x==0) return 0;
    memset(has,false,sizeof(has));
    for(int i=N;i>=1;i--)
    {
        if(a[i]==x)
        {
            for(int j=i;j<=N;j++)
            {
                if(has[a[j]])
                {
                    while(ans.back()!=a[j]) has[ans.back()]=false,ans.pop_back();
                    ans.pop_back();
                    has[a[j]]=false;
                    continue;
                }
                ans.push_back(a[j]);
                has[a[j]]=true;
            }
            for(auto x:ans) printf("%d ",x);
            return 0;
        }
    }
}
