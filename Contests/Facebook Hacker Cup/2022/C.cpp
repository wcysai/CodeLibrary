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
int T,n;
string str;
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        cin>>str;
        printf("Case #%d:\n",t);
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<=i;j++) printf("%c",'.'+'-'-str[0]);
            cout<<str<<endl;
        }
    }
    return 0;
}

