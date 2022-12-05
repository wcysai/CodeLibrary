#pragma GCC optimize(3)
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
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='.')
        {
            if(i>0&&str[i-1]=='L') continue;
            if(i<n-1&&str[i+1]=='L') continue;
            str[i]='C';
        }
    }
    cout<<str<<endl;
    return 0;
}

