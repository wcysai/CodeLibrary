#include<bits/stdc++.h>
#define MAXN 150005
#define MAXM 40005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef bitset<150000> bs;
int n,m,a[MAXN],b[MAXM]; 
vector<P> v1,v2;
bs cur,all;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        v1.push_back(P(a[i],i));
    }
    for(int i=1;i<=m;i++) 
    {
        scanf("%d",&b[i]);
        v2.push_back(P(b[i],i));
    }
    for(int i=0;i<n;i++) cur.set(i);
    for(int i=0;i<n-m+1;i++) all.set(i);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int now=0;
    for(int i=0;i<m;i++)
    {
        while(now<n&&v1[now].F<v2[i].F)
        {
            cur.reset(v1[now].S-1);
            now++;
        }
        all=all&(cur>>(v2[i].S-1));
    }
    printf("%d\n",(int)all.count());
    return 0;
}