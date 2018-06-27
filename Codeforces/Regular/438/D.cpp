#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
char str[2*MAXN][40005];
bool fsb[32768];
int n,m;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",str[i]);
    scanf("%d",&m);
    int now=n;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        x--,y--;
        int len1=strlen(str[x]),len2=strlen(str[y]);
        for(int j=0;j<len1;j++)
            str[now][j]=str[x][j];
        for(int j=len1;j<len1+len2;j++)
            str[now][j]=str[y][j-len1];
        for(int k=15;k>=0;k--)
        {
            if(k==0)
            {
                printf("0\n");
                break;
            }
            memset(fsb,false,sizeof(fsb));
            int tmp=0,cnt=0;
            if(len1+len2<(1<<k)+k-1) continue;
            for(int j=0;j<k;j++)
                tmp=tmp*2+str[now][j]-48;
            fsb[tmp]=true;
            cnt++;
            for(int j=k;j<len1+len2;j++)
            {
                if(tmp>=(1<<(k-1))) tmp-=(1<<(k-1));
                tmp*=2;
                tmp+=str[now][j]-48;
                if(!fsb[tmp]) {fsb[tmp]=true; cnt++;}
            }
            if(cnt==(1<<k))
            {
                printf("%d\n",k);
                break;
            }
        }
        now++;
    }
    return 0;
}
