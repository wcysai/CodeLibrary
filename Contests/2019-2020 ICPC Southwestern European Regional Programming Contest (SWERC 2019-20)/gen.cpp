#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
string str="SPDC";
string gen()
{
    string s="";
    for(int i=0;i<10000;i++)
    {
        s+=str[wcy()%4];
    }
    return s;
}
int main()
{
    freopen("D.in","w",stdout);
    string s=gen(),t=s;
    cout<<s<<endl;
    cout<<t<<endl;
}