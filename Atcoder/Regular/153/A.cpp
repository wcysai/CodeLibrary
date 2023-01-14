#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    int fst=(n-1)/100000+1; n-=(fst-1)*100000;
    printf("%d%d",fst,fst);
    n--;
    vector<int> v;
    int x=10000;
    for(int i=0;i<5;i++){
         v.push_back(n/x); n=n%x;
        x/=10;
    }
    printf("%d%d%d%d%d%d%d\n",v[0],v[1],v[2],v[2],v[3],v[4],v[3]);
    return 0;
}

