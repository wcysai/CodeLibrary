#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int main()
{
    str="";
    for(int i=0;i<26;i++)
    {
        int x;
        scanf("%d",&x);
        str+=(char)('a'+x-1);
    }
    cout<<str<<endl;
    return 0;
}