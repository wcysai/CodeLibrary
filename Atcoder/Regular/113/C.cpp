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
string str;
int main()
{
    cin>>str;
    n=(int)str.size();
    ll ans=0;
    int cnt=0;
    int last=-1;
    for(int i=0;i<n;i++)
    {
        int id=str[i]-'a';
        if(id!=last) ans+=cnt; else ans+=cnt-1;
        if(i>0&&str[i]==str[i-1])
        {
            int id=str[i]-'a';
            if(id!=last)
            {
                last=id;
                cnt++;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}