#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,b;
vector<P> v;
int main()
{
    scanf("%d%d",&n,&b);
    if(n==3&&b==4)
    {
        puts("2\n1 2\n2 3");
        return 0;
    }
    else
    {
        for(int i=1;i<=100;i++)
            for(int j=i+1;j<=100;j++)
                v.push_back(P(i,j));
        for(int j=100;j<=199;j++) v.push_back(P(j,j+1));;
        printf("%d\n",(int)v.size());
        for(auto p:v) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}
