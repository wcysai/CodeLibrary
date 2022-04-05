#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char str[MAXN];
int n;
int main()
{
	scanf("%s",str+1);
	n=strlen(str+1);
	sort(str+1,str+n+1);
	printf("%s\n",str+1);
	return 0;
}