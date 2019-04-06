#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
string str;
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        cin>>str;
        printf("Case #%d: ",t);
        for(int i=0;i<2*n-2;i++) printf("%c",'E'+'S'-str[i]);
        printf("\n");
    }
    return 0;
}
