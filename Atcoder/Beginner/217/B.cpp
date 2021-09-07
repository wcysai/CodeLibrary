#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
set<string> s;
string t;
int main()
{
    s.clear();
    s.insert("ABC");
    s.insert("ARC");
    s.insert("AGC");
    s.insert("AHC");
    cin>>t; s.erase(s.find(t));
    cin>>t; s.erase(s.find(t));
    cin>>t; s.erase(s.find(t));
    assert(s.size()==1);
    cout<<*s.begin()<<endl;
    return 0;
}