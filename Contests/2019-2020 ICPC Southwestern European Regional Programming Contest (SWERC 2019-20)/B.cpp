#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
map<string,int> mp;
string str;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        mp[str]++;
    }
    for(auto p:mp)
    {
        if(p.S*2>n)
        {
            cout<<p.F<<endl;
            return 0;
        }
    }
    cout<<"NONE"<<endl;
    return 0;
}


