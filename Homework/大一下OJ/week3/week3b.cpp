#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAXN 300
using namespace std;
char a[MAXN];
int save[5];
int main()
{
    while(gets(a))
    {
    if(strlen(a)==5)
    {
        for(int i=0;i<5;i++)
        {
            if(a[i]=='0') printf("11000");
            if(a[i]=='1') printf("00011");
            if(a[i]=='2') printf("00101");
            if(a[i]=='3') printf("00110");
            if(a[i]=='4') printf("01001");
            if(a[i]=='5') printf("01010");
            if(a[i]=='6') printf("01100");
            if(a[i]=='7') printf("10001");
            if(a[i]=='8') printf("10010");
            if(a[i]=='9') printf("10100");
            if(i!=4) printf(" ");
        }
        printf("\n");
    }
    else  if(strlen(a)==29)
    {
        int f,sum;
        for(int i=0;i<5;i++)
        {
            f=2,sum=0;
            for(int j=6*i;j<6*i+5;j++)
            {
                if (a[j]=='1')
                {
                    if(j%6==0) sum+=7;
                    if(j%6==1) sum+=4;
                    if(j%6==2) sum+=2;
                    if(j%6==3) sum+=1;
                    f--;
                }
                if(f<0) break;
            }
            if(f!=0)
            {
                printf("error\n");
                break;
            }
            if(sum==11) save[i]=0; else save[i]=sum;
        }
        if(f==0)
        {
            for(int i=0;i<5;i++)
                printf("%d",save[i]);
            printf("\n");
        }
    }
    else printf("error\n");
    }
    return 0;
}
