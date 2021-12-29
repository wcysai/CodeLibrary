#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a,b;
vector<P> solve(int n,int m,int a,int b)
{
    //printf("%d %d %d %d\n",n,m,a,b);
    if(n==2)
    {
        vector<P> v; 
        for(int i=1;i<=b-1;i++)
        {
            v.push_back(P(1,i)); v.push_back(P(2,i));
        }
        v.push_back(P(3-a,b));
        for(int i=b+1;i<=m;i++) v.push_back(P(1,i)); 
        for(int i=m;i>=b+1;i--) v.push_back(P(2,i));
        v.push_back(P(a,b));
        return v;
    }
    else if(a!=1&&(!(a==2&&b==m)))
    {
        vector<P> v; 
        for(int i=1;i<=m;i++) v.push_back(P(1,i));
        vector<P> u=solve(n-1,m,a-1,m+1-b);
        for(auto p:u) v.push_back(P(p.F+1,m+1-p.S));
        return v;
    }
    vector<P> v=solve(m,n,b,a);
    for(auto &p:v) swap(p.F,p.S);
    return v;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    auto v=solve(n,m,a,b);
    for(auto p:v) printf("%d %d\n",p.F,p.S);
    return 0;
}