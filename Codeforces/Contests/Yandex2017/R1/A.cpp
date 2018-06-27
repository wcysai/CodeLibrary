#include<bits/stdc++.h>
#define MAXN 205
using namespace std;
int n,a,b;
int t[MAXN];
int main()
{
    scanf("%d %d %d",&n,&a,&b);
    for(int i=0;i<n;i++)
        scanf("%d",&t[i]);
    priority_queue< int, vector<int>, greater<int> > pque;
    for(int i=0;i<n;i++)
    {

        if(!pque.empty())
        {
            int x=pque.top();
            if(x+b<=t[i])
            {
                int k=(pque.size()+1)/2;
                for(int j=0;j<k;j++)
                {
                    printf("%d ",x+b);
                    pque.pop();
                }
            }
        }
        pque.push(t[i]);
        if(pque.size()==a)
        {
            int k=(a+1)/2;
            for(int j=0;j<k;j++)
            {
                printf("%d ",t[i]);
                pque.pop();
            }
        }
    }
    while(!pque.empty())
    {
        int x=pque.top(),k=(pque.size()+1)/2;
        for(int j=0;j<k;j++)
        {
            printf("%d ",x+b);
            pque.pop();
        }
    }
    return 0;
}
