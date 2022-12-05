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
int n,k,a[MAXN];
mt19937 wcy(time(NULL));
string str;
int main()
{
    for(int i=0;i<50000;i++)
    {
        str+=(char)('a'+wcy()%26);
    }
    cout<<str<<endl;
    return 0;
}

