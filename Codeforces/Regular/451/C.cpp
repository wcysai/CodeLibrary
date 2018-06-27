#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,k;
struct phone
{
    char name[10];
    char number[200][10];
    int cnt=0;
}save[20];
bool used[200];
bool suf(char x[],char y[])
{
    int len1=strlen(x),len2=strlen(y);
    if(len1>len2) return false;
    for(int i=len1-1;i>=0;i--)
        if(x[i]!=y[i-len1+len2]) return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    getchar();
    char str[15];
    int res=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s%d",str,&k);
        int id=-1;
        for(int j=0;j<res;j++)
            if(strcmp(str,save[j].name)==0) id=j;
        if(id==-1)
        {
            id=res;
            strcpy(save[id].name,str);
            res++;
        }
        for(int j=save[id].cnt;j<save[id].cnt+k;j++)
            scanf("%s",save[id].number[j]);
        save[id].cnt+=k;
        getchar();
    }
    printf("%d\n",res);
    for(int i=0;i<res;i++)
    {
        memset(used,false,sizeof(used));
        int t=save[i].cnt;
        for(int j=0;j<t;j++)
        {
            if(used[j]) continue;
            for(int p=j+1;p<t;p++)
                if(!used[j]&&!used[p])
                {
                    if(suf(save[i].number[j],save[i].number[p])) {used[j]=true; save[i].cnt--;}
                    else if(suf(save[i].number[p],save[i].number[j])) {used[p]=true; save[i].cnt--;}
                }
        }
        printf("%s %d",save[i].name,save[i].cnt);
        for(int j=0;j<t;j++)
            if(!used[j]) printf(" %s",save[i].number[j]);
        printf("\n");
    }
    return 0;
}

