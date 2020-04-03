#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> v;
int main()
{
    freopen("G.in","w",stdout);
    puts("1");
    puts("500");
    for(int i=1;i<=500*500;i++) v.push_back(i);
    random_shuffle(v.begin(),v.end());
    for(int i=0;i<500*500;i++)
    {
        printf("%d ",v[i]);
        if(i%500==499) puts("");
    }
    
}