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
map<string,int> mp;
string str;
bool has[MAXN];
int main()
{
    memset(has,false,sizeof(has));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        if(str.size()>6) continue;
        if(str[0]=='-') continue;
        int x=0;
        for(int j=0;j<(int)str.size();j++) x=x*10+(str[j]-'0');
        has[x]=true;
    }
    for(int i=0;;i++)
    {
        if(!has[i])
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}


