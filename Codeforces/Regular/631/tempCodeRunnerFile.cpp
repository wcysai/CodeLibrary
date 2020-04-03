#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
vector<int> v;
int main()
{
    scanf("%d%d",&n,&m);
    int cur=n;
    bool f=true;
    ll s=0;
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
        s+=x;
    }
    if(s<n) puts("-1");
    else if(m-1+v.back()>n) puts("-1");
    else
    {
        int rem=n-(m-1+v.back());
        int cur=1;
        for(int i=0;i<(int)v.size();i++) 
        {
            printf("%d ",cur);
            int x=(i==v.size()-1?v[i]:1);
            int can=min(rem,v[i]-x);
            cur+=can+x; rem-=can;
        }
    }
    
    return 0;
}