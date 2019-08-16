#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int T=100000;
string gen(int x)
{
    string str="";
    for(int i=0;i<x;i++) str+=(char)('a'+wcy()%26);
    return str;
}
int main()
{
    freopen("in.txt","w",stdout);
    printf("%d\n",T);
    for(int i=0;i<T;i++)
    {
        cout<<gen(10)<<endl;
    }
}
