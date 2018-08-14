#include<bits/stdc++.h>
#define MAXN 30
#define MAXK 1005
#define MAXM 1005
#define F first
#define S second
using namespace std;
typedef pair<int,pair<int,int> >P;
int n,m,k;
char names[MAXM][15];
P state[MAXM][MAXN]; // 0: unsubmitted 1:attempted 2:accepted
set<int> save;
int solved[MAXM],penalty[MAXM],lastac[MAXM];
bool cmp(int x,int y)
{
    if(solved[x]!=solved[y]) return solved[x]>solved[y];
    if(penalty[x]!=penalty[y]) return penalty[x]<penalty[y];
    if(lastac[x]!=lastac[y]) return lastac[x]<lastac[y];
    return strcmp(names[x],names[y])<0;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    getchar();
    save.clear();
    char str[3000];
    memset(penalty,0,sizeof(penalty));
    memset(solved,0,sizeof(solved));
    memset(lastac,0,sizeof(lastac));
    for(int i=0;i<m;i++)
    {
        gets(str);
        char* tmp=strtok(str," ");
        strcpy(names[i],tmp);
        int k=0;
        tmp=strtok(NULL," ");
        int num=1;
        while(tmp)
        {
            if(*tmp=='+')
            {
                num=2;
                state[i][k].F=2;
                solved[i]++;
            }
            else if(*tmp=='.')
            {
                num=2;
                state[i][k].F=0;
            }
            else if(*tmp=='-')
            {
                num=2;
                state[i][k].F=1;
            }
            else
            {
                if(num==2)
                {
                    state[i][k].S.F=atoi(tmp);
                    num=3;
                }
                else
                {
                    if(state[i][k].F==2) lastac[i]=max(lastac[i],atoi(tmp));
                    if(state[i][k].F==2) state[i][k].S.S=(state[i][k].S.F-1)*20+atoi(tmp); else state[i][k].S.S=state[i][k].S.F*20+atoi(tmp);
                    if(state[i][k].F==2) penalty[i]+=state[i][k].S.S;
                    num=1;
                    k++;
                }
            }
            tmp=strtok(NULL," ");
        }
    }
    int top=0,bottom=0;
    for(int i=0;i<k;i++)
    {
        gets(str);
        char* tmp=strtok(str," ");
        int id=0;
        for(int j=0;j<m;j++)
          if(strcmp(names[j],tmp)==0) {id=j; break;}
        if(i==0) top=id;
        if(i==k-1) bottom=id;
        save.insert(id);
        for(int j=0;j<n;j++)
            state[id][j].F=state[id][j].S.S=state[id][j].S.F=0;
        solved[id]=0;
        penalty[id]=0;
        int k=0;
        tmp=strtok(NULL," ");
        int num=1;
        while(tmp)
        {
            if(*tmp=='+')
            {
                num=2;
                state[id][k].F=2;
                solved[id]++;
            }
            else if(*tmp=='.')
            {
                num=2;
                state[id][k].F=0;
            }
            else if(*tmp=='-')
            {
                num=2;
                state[id][k].F=1;
            }
            else
            {
                if(num==2)
                {
                    state[id][k].S.F=atoi(tmp);
                    num=3;
                }
                else
                {
                    if(state[id][k].F==2) lastac[id]=max(lastac[id],atoi(tmp));
                    if(state[id][k].F==2) state[id][k].S.S=(state[id][k].S.F-1)*20+atoi(tmp); else state[id][k].S.S=state[id][k].S.F*20+atoi(tmp);
                    if(state[id][k].F==2) penalty[id]+=state[id][k].S.S;
                    num=1;
                    k++;
                }
            }
            tmp=strtok(NULL," ");
        }
    }
    for(int i=0;i<m;i++)
    {
        if(save.count(i)==0)
        {
            bool f=true;
            for(auto it=save.begin();it!=save.end();it++)
                if(!cmp(*it,i)) {f=false; break;}
            if(f) continue;
            f=true;
            lastac[i]=solved[i]==n?lastac[i]:240;
            solved[i]=n;
            penalty[i]=0;
            for(int j=0;j<n;j++)
                if(state[i][j].F==2) penalty[i]+=state[i][j].S.S; else penalty[i]+=240+state[i][j].S.F*20;
            for(auto it=save.begin();it!=save.end();it++)
                if(!cmp(i,*it)) {f=false; break;}
            if(!f)
            {
                printf("Fake\n");
                return 0;
            }
        }
    }
    printf("Leaked\n");
    return 0;
}
