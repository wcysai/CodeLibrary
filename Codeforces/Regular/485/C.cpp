/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-30 01:01:44
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 5000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN];
bool connected[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    sort(a,a+m);
    memset(connected,false,sizeof(connected));
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        int sup=max(0,(1<<n)-1-a[i]),sub=sup;
        bool f=true;
        do
        {
            //printf("%d\n",sub);
            if(connected[sub]) 
            {
                f=false;
                break;
            }
            sub=(sub-1)&sup;
        }while(sub!=sup);
        if(f) cnt++;
        connected[a[i]]=true;
    }
    printf("%d\n",cnt);
    return 0;
}

