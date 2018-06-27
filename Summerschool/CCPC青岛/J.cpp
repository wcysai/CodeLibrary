#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000
using namespace std;
int query,n;
int a[MAXN];
int main()
{
    scanf("%d",&query);
    while(query--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        stack<int> st;
        int k=0;
        while(k<n)
        {
            while(a[k]<=a[k+1]&&k<n-1)
            {
                if(!st.empty()&&st.top()>a[k])
                {
                    st.pop();
                    k++;
                }
                else
                {
                    st.push(a[k]);
                    k++;
                }
            }
            if(k==n-1)
            {
                st.push(a[k]);
                break;
            }
            while(a[k]>a[k+1]&&k<n-1)
                k++;
            if(k==n-1)
               break;
            k++;
        }
        int a[MAXN],k=0;
        while(!st.empty())
        {
            printf("%d ",st.top());
            st.pop();
        }
        printf("\n");
    }
    return 0;
}
