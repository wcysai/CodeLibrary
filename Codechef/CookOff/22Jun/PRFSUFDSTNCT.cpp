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
int t,n,k,p[MAXN],s[MAXN],ans[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) scanf("%d",&s[i]);
        if(p[1]!=1||s[n]!=1) {puts("NO"); continue;}
        bool f=true;
        for(int i=2;i<=n;i++) if((p[i]!=p[i-1])&&(p[i]!=p[i-1]+1)) {f=false; break;}
        for(int i=n-1;i>=1;i--) if((s[i]!=s[i+1])&&(s[i]!=s[i+1]+1)) {f=false; break;}
        int tot=0;
        vector<int> st;
        for(int i=1;i<=n;i++)
        {
            int difpre=(i==1||p[i]!=p[i-1])?1:0;
            int difsuf=(i==n||s[i]!=s[i+1])?1:0;
            if(difpre&&difsuf) continue;
            if((!difpre)&&(!difsuf)) {if(!st.size()) {f=false; break;} continue; }
            if(difpre)
            {
                st.push_back(++tot);
            }
            else
            {
                if(!st.size()) {f=false; break;}
                st.pop_back();
            }
        }
        if(st.size()) f=false;
        if(!f) puts("NO");
        else puts("YES");
    }
    return 0;
}

