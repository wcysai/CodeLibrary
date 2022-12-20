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
int t,n,k,a[MAXN];
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str;
        int x=0;
        for(int i=1;i<n;i++)
        {
            if(str[i]=='1')
            {
                if(x) cout<<'+';
                else cout<<'-';
                x^=1;
            }
            else cout<<'+';
        }
        cout<<endl;
    }
    return 0;
}

