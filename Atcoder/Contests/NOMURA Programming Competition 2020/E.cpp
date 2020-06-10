#include<bits/stdc++.h>
#define MAXN 200005
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
    ll ans=0;
    int last=0,cur=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='1')
        {
            ans+=i/2+1;
            if(last) cur++,last--;
            else last++;
        }
        else
        {
            if(last==1) {cur++; last=0;}
            ans+=cur;
        }
    }
    printf("%lld\n",ans);
    return 0;
}