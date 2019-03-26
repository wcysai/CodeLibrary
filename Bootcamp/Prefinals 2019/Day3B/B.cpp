#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define prev adkoadlpsa
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
typedef vector<VI> VVI;
int n;
pair<int,VI> GetMinCut(VVI &weights)
{
    int N=weights.size();
    VI used(N),cut,best_cut;
    int best_weight=-1;
    for(int phase=N-1;phase>=0;phase--)
    {
        VI w=weights[0];
        VI added=used;
        int prev,last=0;
        for(int i=0;i<phase;i++)
        {
            prev=last;
            last=-1;
            for(int j=1;j<N;j++) if(!added[j]&&(last==-1||w[j]>w[last])) last=j;
            if(i==phase-1)
            {
                for(int j=0;j<N;j++) weights[prev][j]+=weights[last][j];
                for(int j=0;j<N;j++) weights[j][prev]=weights[prev][j];
                used[last]=true;
                cut.push_back(last);
                if(best_weight==-1||w[last]<best_weight)
                {
                    best_cut=cut;
                    best_weight=w[last];
                }
            }
            else
            {
                for(int j=0;j<N;j++) w[j]+=weights[last][j];
                added[last]=true;
            }
        }
    }
    return make_pair(best_weight,best_cut);
}
VVI G;
char str[MAXN][MAXN];
bool cut[MAXN];
int main()
{
    scanf("%d",&n); assert(n<=50); 
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    G.resize(n);
    for(int i=0;i<n;i++) G[i].resize(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            G[i][j]=str[i][j]-'0';
    auto ans=GetMinCut(G);
    assert(ans.F!=-1);
    memset(cut,false,sizeof(cut));
    sort(ans.S.begin(),ans.S.end());
    for(auto x:ans.S) {printf("%d ",x+1); cut[x+1]=true;} 
    puts("");
    for(int i=1;i<=n;i++) if(!cut[i]) printf("%d ",i);
    puts("");
    return 0;
}
