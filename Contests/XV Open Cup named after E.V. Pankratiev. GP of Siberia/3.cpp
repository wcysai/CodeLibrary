#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T;
char sb[MAXN];
int lenb;
int p[MAXN],ex[MAXN];
bool valid[MAXN];
void exkmp()
{
    for(int i=1;i<=lenb;i++) p[i]=ex[i]=0;
    p[1]=lenb;
    int x=1;
    while(sb[x]==sb[x+1]&&x+1<=lenb) x++;
    p[2]=x-1;
    int k=2;
    for(int i=3;i<=lenb;i++)
    {
        int pp=k+p[k]-1,L=p[i-k+1];
        if(i+L<pp+1) p[i]=L;
        else
        {
            int j=pp-i+1;
            if(j<0) j=0;
            while(sb[j+1]==sb[i+j]&&i+j<=lenb) j++;
            p[i]=j;
            k=i;
        }
    }
    x=1;
    while(sb[x]==sb[x]&&x<=lenb) x++;
    ex[1]=x-1;
    k=1;
    for(int i=2;i<=lenb;i++)
    {
        int pp=k+ex[k]-1,L=p[i-k+1];
        if(i+L<pp+1) ex[i]=L;
        else
        {
            int j=pp-i+1;
            if(j<0) j=0;
            while(sb[j+1]==sb[i+j]&&i+j<=lenb&&j<=lenb) j++;
            ex[i]=j;
            k=i;
        }
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",sb+1);
        lenb=strlen(sb+1);
        exkmp();
        for(int i=1;i<=lenb;i++) valid[i]=true;
        for(int i=1;i<=lenb-1;i++)
            for(int j=i+2;j<=lenb;j+=i+1)
                if(ex[j]<min(i,lenb-j+1))
                {
                    valid[i]=false;
                    break;
                }
        for(int k=2;k<=lenb+1;k++)
        {
            bool f=true;
            for(ll j=k-1;j<=lenb;j=j*k+(k-1))
            {
                if(!valid[j])
                {
                    f=false;
                    break;
                }
            }
            if(f)
            {
                printf("%d\n",k);
                break;
            }
        }
    }
    return 0;
}
