#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
char str[MAXN];
int n,num,x,tmp,id;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        str[i]='0';
    printf("? %s\n",str);
    fflush(stdout);
    scanf("%d",&num);
    str[0]='1';
    printf("? %s\n",str);
    fflush(stdout);
    scanf("%d",&x);
    if(x==num-1) id=1; else id=0;
    str[0]='0';
    int save=num;
    if(id==0)
    {
        int left=1,right=n-1;
        while(true)
        {
            int mid=(left+right)/2;
            for(int i=left;i<=mid;i++)
                str[i]=97-(int)str[i];
            printf("? %s\n",str);
            fflush(stdout);
            scanf("%d",&x);
            x=x-save;
            int len=mid-left+1;
            int dif=str[left]=='0'?(x+len)/2:(len-x)/2;
            if(dif==len) break;
            if(right-mid==num-dif)
            {
                left=mid+1;
                break;
            }
            if(dif<=num/2)
            {
                left=mid+1;
                num=num-dif;
            }
            else
            {
                right=mid;
                num=dif;
            }
            save=x+save;
        }
        printf("! %d %d\n",1,left+1);
    }
    else
    {
        save=n-num;
        int left=1,right=n-1;
        while(true)
        {
            int mid=(left+right)/2;
            for(int i=left;i<=mid;i++)
                str[i]=97-(int)str[i];
            printf("? %s\n",str);
            fflush(stdout);
            scanf("%d",&x);
            x=x-save;
            int len=mid-left+1;
            int dif=str[left]=='1'?(x+len)/2:(len-x)/2;
            if(dif==len) break;
            if(right-mid==num-dif)
            {
                left=mid+1;
                break;
            }
            if(dif<=num/2)
            {
                left=mid+1;
                num=num-dif;
            }
            else
            {
                right=mid;
                num=dif;
            }
            save=save+x;
        }
        printf("! %d %d\n",left+1,1);
    }
    return 0;
}
