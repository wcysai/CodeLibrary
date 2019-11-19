#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,L,a[MAXN];
int main()
{
    scanf("%d%d",&N,&L);
    for(int i=1;i<=N;i++) scanf("%d",&a[i]);
    int id=-1;
    for(int i=1;i<=N-1;i++)
    {
        if(a[i]+a[i+1]>=L)
        {
            id=i;
            break;
        }
    }
    if(id==-1) {puts("Impossible"); return 0;}
    puts("Possible");
    for(int i=1;i<id;i++) printf("%d\n",i);
    for(int i=N-1;i>=id+1;i--) printf("%d\n",i);
    printf("%d\n",id);
    return 0;
}
