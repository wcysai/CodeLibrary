#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
string str;
int main()
{
    scanf("%d%d",&n,&q);
    cin>>str;
    int shift=0;
    for(int i=0;i<q;i++)
    {
        int type,x;
        scanf("%d%d",&type,&x);
        if(type==1) {shift+=x; shift%=n;}
        else
        {
            x--;
            int pos=(x-shift+n)%n;
            printf("%c\n",str[pos]);
        }
    }
    return 0;
}

