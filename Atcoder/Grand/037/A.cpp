#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
string str;
int main()
{
    cin>>str;
    n=(int)str.size();
    int ans=1;
    int last=1,now=1;
    while(now<n)
    {
        if(last==2||str[now]!=str[now-1]) {last=1; now++; ans++;}
        else
        {
            last=2; now+=2;
            if(now<=n) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
