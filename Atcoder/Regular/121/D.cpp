#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
P a[MAXN];
int sgn[MAXN];
int ans[MAXN];
string str;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++) 
    {
        scanf("%d",&a[i].F);
        a[i].S=i;
    }
    sort(a+1,a+2*n+1);
    for(int i=1;i<=2*n;i++) if(i<=n) sgn[a[i].S]=-1; else sgn[a[i].S]=1;
    vector<int> st;
    for(int i=1;i<=2*n;i++)
    {
        if(st.size()&&sgn[st.back()]!=sgn[i])
        {
            int v=st.back(); st.pop_back();
            ans[v]=-1; ans[i]=1;
        }
        else st.push_back(i);
    }
    for(int i=1;i<=2*n;i++) if(ans[i]==-1) printf("("); else printf(")");
    return 0;
}