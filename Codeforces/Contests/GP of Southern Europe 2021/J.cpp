#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[3*MAXN];
int sum[3][3*MAXN];
map<pair<P,int>,int > mp;
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=1;i<=3*n;i++)
    {
        int id=str[i]-'A';
        for(int j=0;j<3;j++) sum[j][i]=sum[j][i-1];
        sum[id][i]++;
    }
    if(sum[0][3*n]==n&&sum[1][3*n]==n&&sum[2][3*n]==n) {puts("0"); return 0;}
    int c=0,type=-1;
    for(int i=0;i<3;i++) if(sum[i][3*n]<n) c++,type=i;
    if(c==1)
    {
        int tmp=(type==0?1:0),tmp2=3-type-tmp;
        int need=n-sum[type][3*n];
        for(int i=1;i<=3*n;i++) mp[make_pair(P(sum[tmp][3*n]-sum[tmp][i],sum[tmp2][3*n]-sum[tmp2][i]),i-sum[type][i])]=i;
        for(int i=1;i<=3*n;i++)
        {
            if(mp.find(make_pair(P(n-sum[tmp][i-1],n-sum[tmp2][i-1]),(i-1)-(sum[type][i-1])+need))!=mp.end())
            {
                puts("1");
                printf("%d %d %c\n",i,mp[make_pair(P(n-sum[tmp][i-1],n-sum[tmp2][i-1]),(i-1)-(sum[type][i-1])+need)],'A'+type);
                return 0;
            }
        }
    }
    puts("2");
    int pos=-1;
    type=0;
    for(int i=1;i<=3*n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(sum[j][i]==n)
            {
                type=j;
                pos=i;
                break;
            }
        }
        if(pos!=-1) break;
    }
    int tmp=(type==0?1:0),tmp2=3-type-tmp;
    printf("%d %d %c\n",pos+1,3*n,'A'+tmp);
    printf("%d %d %c\n",pos+1,pos+(n-sum[tmp2][pos]),'A'+tmp2);
    return 0;
}