#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int n,d;
map<vector<int>,int> mp,nmp;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    cin>>str;
    n=(int)str.size();
    scanf("%d",&d);
    vector<int> v(n+1);
    for(int i=0;i<=n;i++) v[i]=i;
    mp[v]=1;
    int ans=0;
    for(int i=0;i<=n+d;i++)
    {
        //printf("%d\n",(int)mp.size());
        for(auto p:mp)
        {
            int val=p.S;
            vector<int> v=p.F;
            if(v[n]==d) add(ans,val);
            vector<int> nv(n+1);
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    if(k>0&&j+'A'==str[k-1]) nv[k]=v[k-1]; else if(k>0) nv[k]=v[k-1]+1; else nv[k]=INF;
                    if(k>0) nv[k]=min(nv[k],nv[k-1]+1);
                    nv[k]=min(nv[k],v[k]+1);
                }
                //for(auto x:nv) printf("%d ",x);
                //puts("");
                add(nmp[nv],val);
            }
        }
        swap(mp,nmp);
        nmp.clear();
    }
    printf("%d\n",ans);
}