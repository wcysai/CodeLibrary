#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str,s;
int n;
vector<string> v;
int main()
{
    freopen("fraud.in","r",stdin);
    freopen("fraud.out","w",stdout);
    cin>>str;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>s;
        bool f=true;
        for(int j=0;j<9;j++)
        {
            if(str[j]!='*'&&str[j]!=s[j])
            {
                f=false;
                break;
            }
        }
        if(f) v.push_back(s);
    }
    printf("%d\n",(int)v.size());
    for(auto s:v) cout<<s<<endl;
    return 0;
}