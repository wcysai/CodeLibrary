/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-01 19:34:04
 ************************************************************************/

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
int n,k,a[MAXN];
vector<int> v={1,2,4,5,7,8,9,10,11,12,13};
vector<int> ans;
int R,F;
int main()
{
    scanf("%d%d",&R,&F);
    ans.push_back(F);
    int mult=(F-1)*2,cur=1;
    for(;;)
    {
        int now=mult*cur+1;
        if(now>300000) break;
        ans.push_back(now);
        cur=cur*3;
    }
    //for(auto it:ans) printf("%d ",it);
    //puts("");
    for(int i=0;i<R;i++)
    {
        int cnt,s=0;
        scanf("%d",&cnt);
        for(int j=0;j<cnt;j++)
        {
            int x;
            scanf("%d",&x);
            if(x<F) continue;
            int id=upper_bound(ans.begin(),ans.end(),x)-ans.begin()-1;
            s^=v[id];
        }
        if(s==0) printf("0"); else printf("1");
        if(i==R-1) printf("\n"); else printf(" ");
    }
    return 0;
}

