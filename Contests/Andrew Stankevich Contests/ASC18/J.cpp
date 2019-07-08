#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN];
bool vis[MAXN][MAXN][2];
bool dp[MAXN][MAXN][2];
int pos[MAXN][MAXN][2];
bool solve(int l,int r,int t)
{
    if(l==r) 
    {
        if(t) return (str[l]=='1');
        return str[l]=='0';
    }
    if(vis[l][r][t]) return dp[l][r][t];
    vis[l][r][t]=true;
    if(str[l]=='!') 
    {
        if(solve(l+1,r,t^1))
        {
            pos[l][r][t]=l;
            return dp[l][r][t]=true; 
        }
    }
    if(t)
    {
        for(int i=l;i<=r;i++)
        {
            if(str[i]=='|')
            {
                if(solve(l,i-1,t)||solve(i+1,r,t))
                {
                    pos[l][r][t]=i;
                    return dp[l][r][t]=true;
                }
            }
            else if(str[i]=='&')
            {
                if(solve(l,i-1,t)&&solve(i+1,r,t))
                {
                    pos[l][r][t]=i;
                    return dp[l][r][t]=true;
                }
            }
        }
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            if(str[i]=='|')
            {
                if(solve(l,i-1,t)&&solve(i+1,r,t))
                {
                    pos[l][r][t]=i;
                    return dp[l][r][t]=true;
                }
            }
            else if(str[i]=='&')
            {
                if(solve(l,i-1,t)||solve(i+1,r,t))
                {
                    pos[l][r][t]=i;
                    return dp[l][r][t]=true;
                }
            }
        }
    }
    return dp[l][r][t]=false;
}
void print(int l,int r,int t)
{
    if(l==r)
    {
        printf("%c",str[l]);
        return;
    }
    int p=pos[l][r][t];
    char ch=str[p];
    if(ch=='!')
    {
        printf("!(");
        print(l+1,r,t^1);
        printf(")");
        return;
    }
    if(t==1)
    {
        if(ch=='&')
        {
            printf("(");
            print(l,p-1,t);
            printf(")&(");
            print(p+1,r,t);
            printf(")");
        }
        else
        {
            if(solve(l,p-1,t))
            {
                printf("(");
                print(l,p-1,t);
                printf(")|(");
                for(int i=p+1;i<=r;i++) printf("%c",str[i]);
                printf(")");
            }
            else
            {
                printf("(");
                for(int i=l;i<=p-1;i++) printf("%c",str[i]);
                printf(")|(");
                print(p+1,r,t);
                printf(")");
            }
        }
    }
    else
    {
        if(ch=='|')
        {
            printf("(");
            print(l,p-1,t);
            printf(")|(");
            print(p+1,r,t);
            printf(")");
        }
        else
        {
            if(solve(l,p-1,t))
            {
                printf("(");
                print(l,p-1,t);
                printf(")&(");
                for(int i=p+1;i<=r;i++) printf("%c",str[i]);
                printf(")");
            }
            else
            {
                printf("(");
                for(int i=l;i<=p-1;i++) printf("%c",str[i]);
                printf(")&(");
                print(p+1,r,t);
                printf(")");
            }
        }
    }
}
int main()
{
    freopen("truth.in","r",stdin);
    freopen("truth.out","w",stdout);
    scanf("%s",str+1);
    n=strlen(str+1);
    memset(vis,false,sizeof(vis));
    if(!solve(1,n,1))
    {
        puts("Impossible");
        return 0;
    }
    print(1,n,1);
    return 0;
}
