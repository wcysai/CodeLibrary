#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<double,double> P;
typedef long long ll;
int n,k,a[MAXN];
P A,B,C,O;
double area(P x,P y,P z)
{
	double x1=y.F-x.F;
	double y1=y.S-x.S;
	double x2=z.F-x.F;
	double y2=z.S-x.S;
	return max(x1*y2-y1*x2,y1*x2-x1*y2)/2.0;
}
int main()
{
	freopen("p102_triangles.txt","r",stdin);
	int ans=0;
	O.F=0;
	O.S=0;
	string str;
	while(scanf("%lf%lf%lf%lf%lf%lf",&A.F,&A.S,&B.F,&B.S,&C.F,&C.S)!=EOF)
	{
		//cout<<str<<endl;
		//printf("%f %f %f %f %f %f\n",A.F,A.S,B.F,B.S,C.F,C.S);
		if(area(A,B,O)+area(B,C,O)+area(A,C,O)==area(A,B,C)) ans++;
	}
	printf("%d\n",ans);
	fclose(stdin);
	return 0;
}