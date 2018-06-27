#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<assert.h>
#define MAXS 3200
#define MAXN 80
using namespace std;
int n,a[MAXN],mini,cnt;
bool used[MAXN];
bool flag;
vector<int> divisor(int n)
{
    vector<int> res;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
void dfs(int num,int x,int s)
{
    if(flag) return;
    if(x==0)
    {
        if(num==n)
        {
            flag=true;
            return;
        }
        else dfs(num,s,s);
    }
    for(int i=n-1;i>=0;i--)
    {
        if(!used[i]&&x>=a[i])
        {
            if(i!=n-1&&a[i]==a[i+1]&&!used[i+1]) continue;
            used[i]=true;
            dfs(num+1,x-a[i],s);
            used[i]=false;
            if(x==s) return;
        }
    }
    return;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        flag=false;
        if(!n) break;
        int s=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        sort(a,a+n);
        int ans=0;
        vector<int> dv=divisor(s);
        for(int i=0;i<dv.size();i++)
        {
            if(dv[i]>=a[n-1])
            {
                memset(used,false,sizeof(used));
                cnt=n;
                dfs(0,dv[i],dv[i]);
                if(flag)
                {
                    printf("%d\n",dv[i]);
                    break;
                }
            }
        }
    }
    return 0;
}

