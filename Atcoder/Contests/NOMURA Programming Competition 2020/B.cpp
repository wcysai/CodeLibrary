#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int main()
{
    cin>>str;
    int n=(int)str.size();
    for(int i=0;i<n;i++) if(str[i]=='?') str[i]='D';
    cout<<str<<endl;
}