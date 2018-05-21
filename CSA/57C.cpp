#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
int state[MAXN];
bool used[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    memset(state,0,sizeof(state));
    for(int i=0;i<2*k;i++)
    {
        int x;
        scanf("%d",&x);
        state[x-1]=i>=k?2:1;
    }
    int ans=0,cnt=0;
    memset(used,false,sizeof(used));
    for(int i=0;i<n;i++)
    {
        int left=i-1;
        if(left==-1) left=n-1;
        int right=i+1;
        if(right==n) right=0;
        if(state[i]==1&&state[right]==2&&!used[i]&&!used[right])
        {
            used[right]=true;
            used[i]=true;
            cnt++;
        }
        if(state[i]==1&&state[left]==2&&!used[i]&&!used[left])
        {
            used[left]=true;
            used[i]=true;
            cnt++;
        }
    }
    ans=max(ans,cnt);
    memset(used,false,sizeof(used));
    cnt=0;
    for(int i=0;i<n;i++)
    {
        int left=i-1;
        if(left==-1) left=n-1;
        int right=i+1;
        if(right==n) right=0;
        if(state[i]==1&&state[left]==2&&!used[i]&&!used[left])
        {
            used[left]=true;
            used[i]=true;
            cnt++;
        }
        if(state[i]==1&&state[right]==2&&!used[i]&&!used[right])
        {
            used[right]=true;
            used[i]=true;
            cnt++;
        }
    }
    ans=max(ans,cnt);
    printf("%d\n",k*2-ans);
    return 0;
}
