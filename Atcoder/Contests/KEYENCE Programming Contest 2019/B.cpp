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
string ss="keyence";
string tt="ecneyek";
int main()
{
    cin>>str;
    string rts=str;
    reverse(rts.begin(),rts.end());
    for(int i=0;i<=7;i++)
    {
        if(str.substr(0,i)==ss.substr(0,i)&&rts.substr(0,7-i)==tt.substr(0,7-i))
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}

