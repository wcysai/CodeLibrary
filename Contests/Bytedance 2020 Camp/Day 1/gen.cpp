#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int p[MAXN];
int main()
{
    freopen("A.in","w",stdout);
    printf("%d\n",1000);
    for(int i=1;i<=1000;i++) p[i]=i;
    random_shuffle(p+1,p+1001);
    for(int i=1;i<=1000;i++) printf("%d ",p[i]);
    puts("");
    printf("%d\n",999);
    for(int i=0;i<999;i++) printf("%d %d\n",1,2+i);
}