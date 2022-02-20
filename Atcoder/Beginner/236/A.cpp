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
    cin>>str;
    int x,y;
    scanf("%d%d",&x,&y);
    swap(str[x-1],str[y-1]);
    cout<<str<<endl;
    return 0;
}