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
typedef vector<int> vec;
typedef vector<vec> mat;
int t,n,m,a[MAXN];
int s[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        mat v(n,vec(m));
        int sum=0;
        for(int i=0;i<n;i++)
        {
            s[i]=0;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&v[i][j]);
                s[i]+=v[i][j];
            }
            sum+=s[i];
        }
        if(sum%n) {puts("-1"); continue;}
        int need=sum/n;
        vector<pair<P,int> > ans;
        for(int j=0;j<m;j++)
        {
            vector<int> sm,gr;
            for(int i=0;i<n;i++)
            {
                if(s[i]<need&&v[i][j]==0) sm.push_back(i);
                if(s[i]>need&&v[i][j]==1) gr.push_back(i);
            }
            int sz=min((int)sm.size(),(int)gr.size());
            for(int i=0;i<sz;i++)
            {
                s[sm[i]]++; s[gr[i]]--;
                ans.push_back(make_pair(P(sm[i]+1,gr[i]+1),j+1));
            }
        }
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%d %d %d\n",p.F.F,p.F.S,p.S);
    }
    return 0;
}

