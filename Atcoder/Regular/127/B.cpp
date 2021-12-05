#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l;
int res[MAXN];
vector<string> v;
string to_ternary(int x)
{
    string str="";
    for(int i=0;i<l;i++)
    {
        str+=(char)('0'+(x%3));
        x/=3;
    }
    reverse(str.begin(),str.end());
    return str;
}
int main()
{
    scanf("%d%d",&n,&l);
    int x=2;
    for(int i=0;i<l-1;i++) x*=3;
    for(int i=0;i<n;i++)
        v.push_back(to_ternary(x+i));
    for(auto x:v)
    {
        cout<<x<<endl;
        for(int i=0;i<l;i++) if(x[i]=='0') cout<<'2'; else cout<<(char)(x[i]-1);
        cout<<endl;
        for(int i=0;i<l;i++) if(x[i]=='2') cout<<'0'; else cout<<(char)(x[i]+1);
        cout<<endl;
    }
    return 0;
}