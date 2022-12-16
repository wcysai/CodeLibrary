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
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int cnt=0;
        multiset<int> s;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]>a[1]) s.insert(a[i]);
        }
        while(s.size())
        {
            int x=*s.begin(); s.erase(s.begin());
            if(x>a[1])
                a[1]=(x+a[1]+1)/2;
        }
        printf("%d\n",a[1]);
    }
    return 0;
}

