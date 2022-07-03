#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],b[MAXN],ans[MAXN];
string str;
bool used[MAXN];
bool check()
{
    memset(used,false,sizeof(used));
    set<int> lb;
    for(int i=1;i<=2*n;i++) if(ans[i]==0) lb.insert(i);
    int cnt=0,now=1,cur=1;
    for(int i=1;i<=2*n;i++)
    {
        while(now<=2*n&&used[now]) now++;
        if(cnt==0&&ans[now]==1)
        {
            int nxt=*lb.begin();
            if(a[i]!=nxt) return false;
            lb.erase(nxt);
            used[nxt]=true;
            cnt++;
        }
        else {if(a[i]!=now) return false; lb.erase(now); used[now]=true; cnt+=(ans[now]==1?-1:1); now++;}
    }
    for(int i=1;i<=2*n;i++) if(ans[i]==0) lb.insert(i);
    cnt=0,now=2*n,cur=1;
    memset(used,false,sizeof(used));
    for(int i=1;i<=2*n;i++)
    {
        while(now>=1&&used[now]) now--;
        if(cnt==0&&ans[now]==1)
        {
            int nxt=*(--lb.end());
            if(b[i]!=nxt) return false;
            lb.erase(nxt);
            used[nxt]=true;
            cnt++;
        }
        else {if(b[i]!=now) return false; lb.erase(now); used[now]=true; cnt+=(ans[now]==1?-1:1); now--;}
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=2*n;i++) scanf("%d",&b[i]);
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=n;i++)
    {
        if(a[2*i-1]>a[2*i])
        {
            ans[a[2*i-1]]=0;
            ans[a[2*i]]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(b[2*i-1]<b[2*i])
        {
            ans[b[2*i-1]]=0;
            ans[b[2*i]]=1;
        }
    }
    string str;
    for(int i=1;i<=2*n;i++) if(ans[i]==-1) {puts("-1"); return 0;} else if(ans[i]==0) str+='('; else str+=')';
    if(!check()) {puts("-1"); return 0;}
    cout<<str<<endl;
    return 0;
}

