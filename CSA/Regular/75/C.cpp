/*************************************************************************
    > File Name: 75C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-04 13:56:41
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<db,int> P;
int N,D,X,Y,d[MAXN],v[MAXN];
vector<P> x,y;
int main()
{
    scanf("%d%d%d",&N,&X,&Y);
    for(int i=1;i<=N;i++) 
    {
        scanf("%d%d",&d[i],&v[i]);
        x.push_back(P((db)d[i]/v[i],i));
        y.push_back(P((db)d[i]/(v[i]-Y),i));
    }
    sort(x.begin(),x.end());sort(y.begin(),y.end());
    for(int i=1;i<=N;i++)
    {
        int ans=lower_bound(x.begin(),x.end(),P((db)d[i]/(v[i]+X),i))-x.begin()+1;
        ans=min(ans,(int)(lower_bound(y.begin(),y.end(),P((db)d[i]/v[i],i))-y.begin()+1));
        printf("%d\n",ans);
    }
    return 0;
}

