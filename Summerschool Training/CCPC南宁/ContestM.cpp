#include<bits/stdc++.h>
#define MAXN 20
#define MAXM 50
#define MAXL 200
using namespace std;
int n,m;
double alpha;
char str[MAXL];
int num[MAXM];
int main()
{
    scanf("%d %lf",&n,&alpha);
    getchar();
    m=0;
    while(gets(str))
    {
        int len=strlen(str);
        int d=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]==' ')
            {
                if(d!=0) num[m]|=1<<(d-1);n
                d=0;
            }
            else
                d=d*10+str[i]-48;
        }
        if(d!=0) num[m]|=1<<(d-1);
        m++;
    }
    int ans=0;
    for(int i=1;i< 1<<n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
            if((num[j]|i)==num[j]) cnt++;
        if(cnt>=(int)ceil(m*alpha)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
