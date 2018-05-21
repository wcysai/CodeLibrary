#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define INF 1000000
using namespace std;
int w,h,b[25][25],x,y,x2,y2,f,save,cnt2;
int dir1[4]={1,0,-1,0};
int dir2[4]={0,1,0,-1};
void dfs(int a[25][25],int m,int n,int cnt)
{
	int cnt2,memm,memn;
	memm=m;
	memn=n;
	cnt++;

	if(cnt>10) return;
	for(int i=0;i<4;i++)
	{
	    cnt2=0;
		while(true)
		{
		    cnt2++;
			m+=dir1[i];
			n+=dir2[i];
			if(m==0||n==0||m==h+1||n==w+1)
            {
                m=memm;
                n=memn;
              break;
            }
			if(a[m][n]==3)
			{
				if (save>cnt) save=cnt;
				f=1;
				return;
			}
			if(a[m][n]==1)
			{
			    if(cnt2==1)
			    {
			        m-=dir1[i];
				    n-=dir2[i];
                      break;
			    }
				a[m][n]=0;
				m-=dir1[i];
				n-=dir2[i];
                dfs(a,m,n,cnt);
                m+=dir1[i];
				n+=dir2[i];
                a[m][n]=1;
                m=memm;
                n=memn;
				break;
			}

		}
	}
	return;
}
int main()
{
    memset(b,0,sizeof(b));
    scanf("%d %d",&w,&h);
    while(w!=0&&h!=0)
    {
    f=0;
    save=INF;
    memset(b,0,sizeof(b));
	for(int i=1;i<=h;i++)
	  for(int j=1;j<=w;j++)
	  {
	    scanf("%d",&b[i][j]);
	    if(b[i][j]==2)
	    {
	    	x=i;
	    	y=j;
		}
      }
	dfs(b,x,y,0);
	if(f==1) printf("%d\n",save); else printf("-1\n");
	scanf("%d %d",&w,&h);
    }
    return 0;
}
