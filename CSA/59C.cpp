#include<bits/stdc++.h>
#define MAXN 3005
using namespace std;
int n,k;
char a[MAXN][MAXN];
char str[MAXN];
bool fsb[MAXN];
bool test(int i,int j)
{
    return ((j==0&&fsb[j])||(j==i&&j!=0&&fsb[j-1])||(j!=0&&j!=i&&(fsb[j-1]||fsb[j])));
}
vector<int> save;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",a[i]);
    memset(fsb,false,sizeof(fsb));
    fsb[0]=true;
    str[0]=a[0][0];
    for(int i=1;i<n;i++)
    {
        char ch=(char)123;
        for(int j=0;j<=i;j++)
        {
            bool f=false;
            if (test(i,j)) ch=min(ch,a[i][j]);
        }
        str[i]=ch;
        save.clear();
        for(int j=0;j<=i;j++)
            if(a[i][j]==ch&&test(i,j)) save.push_back(j);
        memset(fsb,false,sizeof(fsb));
        for(int i=0;i<save.size();i++)
            fsb[save[i]]=true;
    }
    printf("%s\n",str);
    return 0;
}
