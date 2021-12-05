#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int main()
{
    scanf("%d",&n);
    if(n<40) printf("%d\n",40-n);
    else if(n<70) printf("%d\n",70-n);
    else if(n<90) printf("%d\n",90-n);
    else puts("expert");
    return 0;
}