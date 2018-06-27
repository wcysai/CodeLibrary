#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
string str;
int n,m;
int num[MAXN];
int main()
{
    scanf("%d",&n);
    cin>>str;
    scanf("%d",&m);
    int cnt=0;
    int k=0;
    memset(num,0,sizeof(num));
    while(k+m-1<n)
    {
        int st=k;
        bool f=true;
        for(int i=st;i<st+m;i++)
        {
            if((i%2==0&&str[i]=='b')||(i%2==1&&str[i]=='a'))
            {
                f=false;
                k=i+1;
                if(k&1)k++;
                break;
            }
        }
        if(f) {num[st]++;num[st+m]--; k=st+m; if(k&1)k++;}
    }
    k=1;
    while(k+m-1<n)
    {
        int st=k;
        bool f=true;
        for(int i=st;i<st+m;i++)
        {
            if((i%2==0&&str[i]=='a')||(i%2==1&&str[i]=='b'))
            {
                f=false;
                k=i+1;
                if(k%2==0) k++;
                break;
            }
        }
        if(f) {num[st]++;num[st+m]--; k=st+m; if(k%2==0) k++;}
    }
    int s=0;
    for(int i=0;i<n;i++)
    {
        s+=num[i];
        if(s>0&&str[i]=='?') cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
