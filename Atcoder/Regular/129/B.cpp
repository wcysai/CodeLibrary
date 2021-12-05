#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<P> v,vv;
int l[MAXN],r[MAXN];
int main()
{
    scanf("%d",&n);
    int minr=INF,maxl=0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&l[i],&r[i]);
        maxl=max(maxl,l[i]); minr=min(minr,r[i]);
        printf("%d\n",max(0,(maxl-minr+1)/2));
    }
    return 0;
}