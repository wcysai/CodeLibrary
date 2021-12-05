#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
vector<int> v;
string ans;
void dec()
{
    for(int i=0;i<(int)v.size();i++)
    {
        if(v[i]==1) {v[i]=0; break;}
        v[i]=1;
    }
}
void go()
{
    while(v.size()&&v.back()==0) v.pop_back();
}
bool is_zero()
{
    go();
    return (v.size()==0);
}
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<(int)str.size();i++) v.push_back(str[i]-'0');
    reverse(v.begin(),v.end());
    dec();
    ans="1";
    while(true)
    {
        if(is_zero()) break;
        if(n==0) break;
        if(v.size()>=n&&v[n-1]==1)
        {
            ans+='1';
            v[n-1]=0;
            go();
        }
        else 
        {
            ans+='0';
            dec();
        }
        n--;
    }
    cout<<ans<<endl;
    return 0;
}