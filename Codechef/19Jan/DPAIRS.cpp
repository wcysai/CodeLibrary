#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,M,A[MAXN],B[MAXN];
vector<P> ans;
set<int> num;
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) scanf("%d",&A[i]);
    for(int i=1;i<=M;i++) scanf("%d",&B[i]);
    int minid=-1,minn=INF;
    for(int i=1;i<=N;i++) if(A[i]<minn) {minid=i; minn=A[i];}
    for(int i=1;i<=M;i++) ans.push_back(P(minid-1,i-1));
    int maxid=-1,maxn=-INF;
    for(int i=1;i<=M;i++) if(B[i]>maxn) {maxid=i; maxn=B[i];}
    for(int i=1;i<=N;i++)
    {
        if(i==minid) continue;
        ans.push_back(P(i-1,maxid-1));
    }
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}
