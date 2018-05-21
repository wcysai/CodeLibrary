#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 100005
using namespace std;
typedef pair<int,int> P;
string str[MAXN];
int n,m,k;
int cost1[MAXM],cost2[MAXM],dif[MAXM];
vector<P> save;
int cnt[26];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        cin>>str[i];
    memset(cost1,0,sizeof(cost1));
    memset(cost2,0,sizeof(cost2));
    for(int i=0;i<m/2;i++)
        for(int j=0;j<n;j++)
            cost1[i]+=str[j][i]==str[j][m-1-i]?0:1;
    for(int i=0;i<(m+1)/2;i++)
    {
        if(i==m-1-i)
            for(int j=0;j<n/2;j++)
                cost2[i]+=str[j][i]==str[n-1-j][i]?0:1;
        else
            for(int j=0;j<(n+1)/2;j++)
            {
                if(j==n-1-j)
                    cost2[i]+=str[j][i]==str[j][m-1-i]?0:1;
                else
                {
                    int a=str[j][i]-'a';
                    int b=str[j][m-1-i]-'a';
                    int c=str[n-1-j][i]-'a';
                    int d=str[n-1-j][m-1-i]-'a';
                    cnt[a]++;
                    cnt[b]++;
                    cnt[c]++;
                    cnt[d]++;
                    int x=max(max(cnt[a],cnt[b]),max(cnt[c],cnt[d]));
                    cnt[a]=cnt[b]=cnt[c]=cnt[d]=0;
                    cost2[i]+=4-x;
                }
            }
    }
    int sum=0;
    for(int i=0;i<m/2;i++)
    {
        dif[i]=cost2[i]-cost1[i];
        sum+=cost1[i];
        save.push_back(P(dif[i],i));
    }
    if(m%2==1&&k%2==1)
        save.push_back(P(cost2[m/2],m/2));
    sort(save.begin(),save.end());
    for(int i=0;i<(k+1)/2;i++)
        sum+=save[i].first;
    printf("%d\n",sum);
    return 0;
}

