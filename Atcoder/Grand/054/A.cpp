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
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    if(str[0]!=str[n-1]) {puts("1"); return 0;}
    for(int i=1;i<n-2;i++)
    {
    	if(str[i]!=str[0]&&str[i+1]!=str[0])
    	{
    		puts("2");
    		return 0;
    	}
    }
    puts("-1");
    return 0;
}