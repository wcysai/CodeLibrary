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
    n=(int)str.size();
    vector<char> v;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='T')
        {
            if(v.size()&&v.back()=='S') v.pop_back();
            else v.push_back('T');
        }
        else v.push_back(str[i]);
    }
    printf("%d\n",(int)v.size());
    return 0;
}