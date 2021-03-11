#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string s1,s2,s3;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>s1;
        cin>>s2;
        cin>>s3;
        for(int i=0;i<n;i++) printf("0");
        for(int i=0;i<n;i++) printf("1");
        puts("0");
    }
    return 0;
}