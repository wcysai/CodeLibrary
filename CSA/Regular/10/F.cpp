#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int N;
db ans;
db harm[MAXN],harm2[MAXN];
int main()
{
    scanf("%d",&N);
    harm[0]=harm2[0]=0;
    for(int i=1;i<=N;i++) harm[i]=harm[i-1]+((db)1/i);
    for(int i=1;i<=N;i++) harm2[i]=harm2[i-1]+((db)1/(1LL*i*i));
    ans=0;
    for(int i=1;i<=N;i++) ans+=(harm[N-1]-harm[i-1]);
    ans+=N-1;
    ans+=(harm[N-1]*harm[N-1]-harm2[N-1]);
    for(int i=2;i<=N-1;i++)
    {
        ans+=2*(harm[N-1]-harm[i-1]);
        ans+=(harm[N-1]-harm[i-1])*(harm[N-1]-harm[i-1])-harm2[N-1]+harm2[i-1];
        //printf("%.10Lf\n",ans);
    }
    printf("%.10Lf\n",ans);
    return 0;
}

