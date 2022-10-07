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
int t;
string str;
int cnt[30];
char go()
{
    int now=0;
    for(int i=0;i<n/k;i++)
    {
        if(cnt[now]) {cnt[now]--; now++; continue;}
        bool f=false;
        for(int j=now+1;j<26;j++)
        {
            if(cnt[j])
            {
                cnt[j]--;
                f=true;
                break;
            }
        }
        if(f) continue;
        for(int j=now;j>=0;j--)
        {
            if(cnt[j])
            {
                cnt[j]--;
                break;
            }
        }
    }
    return 'a'+now;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        memset(cnt,0,sizeof(cnt));
        cin>>str;
        for(int i=0;i<(int)str.size();i++) cnt[str[i]-'a']++;
        for(int i=0;i<k;i++) cout<<go();
        cout<<endl;
    }
    return 0;
}

