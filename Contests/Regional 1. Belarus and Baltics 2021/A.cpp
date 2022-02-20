#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        if(i%m<k) printf("1"); else printf("0");
    return 0;
}