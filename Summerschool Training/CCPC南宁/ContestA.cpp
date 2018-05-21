#include<bits/stdc++.h>
#define MAXN 5
double mkv[MAXN][MAXN];
char str[50];
int num[20];
int main()
{
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            scanf("%lf",&mkv[i][j]);
    getchar();
    gets(str);
    int len=strlen(str);
    int k=0;
    for(int i=0;i<len;i++)
        if(str[i]>='0'&&str[i]<='9')
            num[k]=str[i]-48,k++;
    double p=1;
    for(int i=1;i<k;i++)
        p*=mkv[num[i-1]][num[i]];
    printf("%.8lf\n",p);
    gets(str);
    len=strlen(str);
    k=0;
    for(int i=0;i<len;i++)
        if(str[i]>='0'&&str[i]<='9')
            num[k]=str[i]-48,k++;
    p=1;
    for(int i=1;i<k;i++)
        p*=mkv[num[i-1]][num[i]];
    printf("%.8lf\n",p);
    int x;
    scanf("%d",&x);
    printf("%.8lf\n",1/(1-mkv[x][x]));
    scanf("%d",&x);
    printf("%.8lf\n",1/(1-mkv[x][x]));
    return 0;
}
