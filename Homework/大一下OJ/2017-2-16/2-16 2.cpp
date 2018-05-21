#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define MAXN 120
#define MAXM 100
using namespace std;
char save[MAXN][MAXM];
char str[MAXM+6];
int n;
int main()
{
    strcpy(save[0],"http://www.acm.org/");
    int k=0,m=0;
    while (true)
    {
        gets(str);
        if(str[0]=='Q') break;
        if(str[0]=='B')
        {
            if(k==0)
                printf("Ignored\n");
             else
            {
                k--;
                printf("%s\n",save[k]);
            }
        }
        if(str[0]=='V')
        {
            k++;
            memset(save[k],0,sizeof(save[k]));
            for(int i=0;i<strlen(str)-6;i++)
              save[k][i]=str[i+6];

            printf("%s\n",save[k]);
            m=k;
        }
        if(str[0]=='F')
        {
            if(k==m)
                printf("Ignored\n");
            else
            {
                k++;
                printf("%s\n",save[k]);
            }
        }
    }
    return 0;
}

