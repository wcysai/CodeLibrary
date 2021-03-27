#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,c;
vector<int> construct(int m,int c)
{
    if(m==1)
    {
        assert(c==0);
        return vector<int>{n};
    }
    int num=min(c,m-1);
    vector<int> tmp=construct(m-1,c-num);
    reverse(tmp.begin(),tmp.begin()+num);
    tmp.insert(tmp.begin()+num,n-m+1);
    return tmp;
}
int main()
{
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d%d",&n,&c);
        printf("Case #%d: ",_);
        if(c<n-1||c>n*(n+1)/2-1)
        {
            puts("IMPOSSIBLE");
            continue;
        }
        vector<int> v=construct(n,c-(n-1));
        for(auto x:v) printf("%d ",x);
        puts("");
    }
    return 0;
}