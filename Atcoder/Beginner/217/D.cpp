#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int l,q;
set<int> s;
int main()
{
    scanf("%d%d",&l,&q);
    s.insert(0); s.insert(l);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x==1) s.insert(y);
        else
        {
            auto it=s.lower_bound(y);
            int r=*it;
            it--;
            int l=*it;
            printf("%d\n",r-l);
        }
    }
    return 0;
}