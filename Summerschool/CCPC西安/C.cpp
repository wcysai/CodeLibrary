#include<bits/stdc++.h>
using namespace std;
char str[10];
int t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int x=strlen(str);
        for(int i=0;i<232;i++)
        {
            printf("1");
            for(int j=0;j<x-1;j++)
                printf("0");
        }
        printf("1\n");
    }
    return 0;
}
