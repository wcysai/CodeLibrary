#include<bits/stdc++.h>
#define MAXN 155
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> g;
int n,ans;
void go(int sum,int mini)
{
    if(sum==0) {ans++; return;}
    if(mini+1>sum) return;
    for(int i=mini+1;i<=sum;i++)
    {
        bool f=true;
        for(auto x:g) if(__gcd(x,i)!=1) f=false;
        if(f)
        {
            g.push_back(i);
            go(sum-i,i);
            g.pop_back();
        }
    }
}
int main()
{
    freopen("data.txt","w",stdout);
    for(int i=1;i<=150;i++) 
    {
        ans=0; go(i,1);
        printf("%d,",ans);
        if(i%20==0) printf("\n");
    }
    return 0;
}
