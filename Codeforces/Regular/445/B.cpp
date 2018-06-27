#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int n,k;
string str[MAXN];
string ans;
int save[26];
bool cmp(string a,string b)
{
    return a.size()>b.size();
}
int main()
{
    scanf("%d",&n);
    int res=0,t=0;
    for(int i=0;i<n;i++)
        cin>>str[i];
    memset(save,-1,sizeof(save));
    sort(str,str+n,cmp);
    ans=str[0];
    int len=str[0].size();
    for(int i=0;i<len;i++)
    {
        if(save[str[0][i]-'a']!=-1)
        {
            printf("NO\n");
            return 0;
        }
        save[str[0][i]-'a']=i;
    }
    for(int i=1;i<n;i++)
    {
        int x=str[i].size();
        bool f=true;
        int t=0;
        for(int j=0;j<x;j++)
            if(save[str[i][j]-'a']!=-1) {f=false; t=j; break;}
        if(f)
        {

            if(str[i]<ans)
            {
                ans=str[i]+ans;
                for(int j=0;j<26;j++)
                    if(save[j]!=-1) save[j]+=x;
                for(int j=0;j<x;j++)
                {
                    if(save[str[i][j]-'a']!=-1)
                    {
                        printf("NO\n");
                        return 0;
                    }
                    save[str[i][j]-'a']=j;
                }
            }
            else
            {
                ans=ans+str[i];
                int p=ans.size();
                for(int j=0;j<x;j++)
                {
                    if(save[str[i][j]-'a']!=-1)
                    {
                        printf("NO\n");
                        return 0;
                    }
                    save[str[i][j]-'a']=j+p;
                }
            }
        }
        else
        {
            if(ans.find(str[i])!=string::npos) continue;
            string tmp=str[i].substr(t,x-t);
            if(ans.find(tmp)!=string::npos)
            {
                if(ans.find(tmp)!=0)
                {
                    printf("NO\n");
                    return 0;
                }
                for(int j=0;j<26;j++)
                    if(save[j]!=-1) save[j]+=t;
                for(int j=0;j<t;j++)
                {
                    if(save[str[i][j]-'a']!=-1)
                    {
                        printf("NO\n");
                        return 0;
                    }
                    save[str[i][j]-'a']=j;
                }
                ans=str[i].substr(0,t)+ans;
                continue;
            }
            t=0;
            for(int j=0;j<x;j++)
                if(!save[str[i][j]-'a']||(save[str[i][j]-'a']&&j>0&&save[str[i][j]-'a']!=save[str[i][j-1]-'a']+1)) {t=j; break;}
            tmp=str[i].substr(0,t);
            if(ans.find(tmp)!=string::npos)
            {
                if(ans.find(tmp)+t!=ans.size())
                {
                    printf("NO\n");
                    return 0;
                }
                 int p=ans.size();
                for(int j=t;j<x;j++)
                {
                    if(save[str[i][j]-'a']!=-1)
                    {
                        printf("NO\n");
                        return 0;
                    }
                    save[str[i][j]-'a']=p+j-t;
                }
                ans=ans+str[i].substr(t,x-t);
                continue;
            }
            printf("NO\n");
            return 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}

