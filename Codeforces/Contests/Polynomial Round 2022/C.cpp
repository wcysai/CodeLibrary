#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>str;
        int type=0,len=1;
        for(int i=0;i<n-1;i++)
        {
            if(str[i]=='0')
            {
                if(type==0);
                else
                {
                    type=0;
                    len=i+1;
                }
            }
            else
            {
                if(type==1);
                else
                {
                    type=1;
                    len=i+1;
                }
            }
            printf("%d%c",len,i==n-1?'\n':' ');
        }
        puts("");
    }
    return 0;
}

