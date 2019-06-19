#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot,grundy[MAXN];
vector<int> ans[MAXN]=
{
{1,2,},
{1,4,},
{2,4,},
{1,2,4,},
{1,8,},
{2,8,},
{1,2,8,},
{4,8,},
{1,4,8,},
{2,4,8,},
{1,2,4,8,},
{2,3,5,6,},
{1,2,3,5,6,},
{3,4,5,6,},
{1,3,4,5,6,},
{1,3,7,9,},
{1,2,3,4,5,6,},
{1,2,3,7,9,},
{1,3,5,6,8,},
{1,3,4,7,9,},
{1,2,3,5,6,8,},
{1,2,3,4,7,9,},
{1,2,3,10,11,},
{1,2,5,9,11,},
{1,2,3,4,5,6,8,},
{1,2,3,5,9,10,},
{1,2,3,4,10,11,},
{1,2,3,6,9,11,},
{1,2,3,4,5,7,11,},
{1,2,3,4,5,9,10,},
{1,2,3,4,12,13,},
{1,2,3,4,6,9,11,},
{1,2,3,5,7,8,11,},
{1,2,3,5,8,9,10,},
{1,2,3,4,8,10,11,},
{1,2,3,6,8,9,11,},
{1,2,3,4,5,7,8,11,},
{1,2,3,4,5,8,9,10,},
{1,2,3,4,8,12,13,},
{1,2,3,4,6,8,9,11,},
{1,2,3,9,13,17,},
{1,2,3,4,7,12,17,},
{1,2,3,4,8,14,15,},
{1,2,3,6,8,13,15,},
{1,2,3,4,9,13,17,},
{1,2,3,4,5,8,12,15,},
{1,2,3,4,8,16,17,},
{1,2,3,4,6,8,13,15,},
{1,2,3,4,5,7,12,19,},
{1,2,3,4,5,9,12,18,},
{1,2,3,4,6,7,13,19,},
{1,2,3,4,5,6,7,12,16,},
{1,2,3,4,5,7,9,12,14,},
{1,2,3,4,5,6,7,9,10,11,},
{1,2,3,4,5,6,9,12,17,},
{1,2,3,4,5,6,7,14,18,},
{1,2,3,4,5,6,10,12,18,},
{1,2,3,4,5,6,7,9,12,13,},
{1,2,3,4,5,6,9,14,19,},
{1,2,3,4,5,6,7,8,12,16,},
{1,2,3,4,5,7,8,9,12,14,},
{1,2,3,4,5,6,7,8,9,10,11,},
{1,2,3,4,5,6,8,9,12,17,},
{1,2,3,4,5,6,7,8,14,18,},
{1,2,3,4,5,6,8,10,12,18,},
{1,2,3,4,5,6,7,8,9,12,13,},
{1,2,3,4,5,6,8,9,14,19,},
{1,2,3,4,5,6,7,8,10,12,14,},
{1,2,3,4,5,7,8,9,16,18,},
{1,2,3,4,5,6,7,8,9,14,15,},
{1,2,3,4,5,6,8,9,10,12,15,},
{1,2,3,4,5,6,7,22,26,},
{1,2,3,4,5,6,8,9,11,13,15,},
{1,2,3,4,5,6,7,8,9,16,17,},
{1,2,3,4,5,6,8,10,11,14,15,},
{1,2,3,4,5,6,7,8,10,16,18,},
{1,2,3,4,5,6,9,10,11,13,17,},
{1,2,3,4,5,6,7,8,9,18,19,},
{1,2,3,4,5,6,8,9,10,16,19,},
{1,2,3,4,5,6,7,8,22,26,},
{1,2,3,4,5,6,8,9,11,17,19,},
{1,2,3,4,5,6,7,8,9,10,12,19,},
{1,2,3,4,5,6,8,9,10,11,12,16,},
{1,2,3,4,5,6,7,8,9,11,13,19,},
{1,2,3,4,5,6,8,9,10,11,13,17,},
{1,2,3,4,5,6,7,8,9,22,23,},
{1,2,3,4,5,6,8,9,10,11,14,18,},
{1,2,3,4,5,6,7,12,20,32,},
{1,2,3,4,5,6,8,9,10,11,15,19,},
{1,2,3,4,5,6,7,8,9,24,25,},
{1,2,3,4,5,6,8,9,12,13,14,18,},
{1,2,3,4,5,6,7,8,10,24,26,},
{1,2,3,4,5,6,8,9,12,13,15,19,},
{1,2,3,4,5,6,7,8,9,26,27,},
{1,2,3,4,5,6,8,9,10,24,27,},
{1,2,3,4,5,6,7,8,12,20,32,},
{1,2,3,4,5,6,8,9,11,25,27,},
{1,2,3,4,5,6,7,8,9,10,20,27,},
{1,2,3,4,5,6,8,9,10,11,20,24,},
{1,2,3,4,5,6,7,8,9,11,21,27,},
{1,2,3,4,5,6,8,9,10,11,21,25,},
{1,2,3,4,5,6,7,8,9,12,14,16,19,},
{1,2,3,4,5,6,8,9,10,11,22,26,},
{1,2,3,4,5,6,7,8,9,12,15,17,19,},
{1,2,3,4,5,6,8,9,10,11,23,27,},
{1,2,3,4,5,6,7,8,9,10,12,13,14,16,},
{1,2,3,4,5,6,8,9,10,12,14,18,19,},
{1,2,3,4,5,6,7,8,9,10,12,13,15,17,},
{1,2,3,4,5,6,8,9,10,13,15,18,19,},
{1,2,3,4,5,6,7,8,9,10,12,14,15,18,},
{1,2,3,4,5,6,8,9,10,12,13,20,22,},
{1,2,3,4,5,6,7,8,9,10,13,14,15,19,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,19,},
{1,2,3,4,5,6,7,8,9,10,12,16,17,18,},
{1,2,3,4,5,6,8,9,10,11,28,32,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,},
{1,2,3,4,5,6,8,9,10,11,29,33,},
{1,2,3,4,5,6,7,8,9,10,12,20,35,},
{1,2,3,4,5,6,8,9,10,11,12,20,32,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,16,17,},
{1,2,3,4,5,6,8,9,10,11,12,17,18,19,},
{1,2,3,4,5,6,7,8,9,10,11,12,14,16,18,},
{1,2,3,4,5,6,8,9,10,11,12,22,34,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,18,19,},
{1,2,3,4,5,6,8,9,10,11,12,13,20,25,},
{1,2,3,4,5,6,7,8,9,10,11,12,22,30,},
{1,2,3,4,5,6,8,9,10,11,12,14,20,26,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,20,21,},
{1,2,3,4,5,6,8,9,10,11,12,13,22,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,14,20,22,},
{1,2,3,4,5,6,8,9,10,11,13,15,21,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,22,23,},
{1,2,3,4,5,6,8,9,10,11,12,17,24,25,},
{1,2,3,4,5,6,7,8,9,10,11,12,16,20,24,},
{1,2,3,4,5,6,8,9,10,11,12,18,24,26,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,24,25,},
{1,2,3,4,5,6,8,9,10,11,12,17,26,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,14,24,26,},
{1,2,3,4,5,6,8,9,10,11,13,19,25,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,26,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,28,33,},
{1,2,3,4,5,6,7,8,9,10,11,13,15,25,27,},
{1,2,3,4,5,6,8,9,10,11,12,14,28,34,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,28,29,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,16,17,18,},
{1,2,3,4,5,6,7,8,9,10,11,12,14,28,30,},
{1,2,3,4,5,6,8,9,10,11,12,13,15,16,17,19,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,30,31,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,20,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,16,28,32,},
{1,2,3,4,5,6,8,9,10,11,12,13,15,21,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,20,31,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,20,24,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,15,21,31,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,21,25,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,16,20,33,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,22,26,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,17,21,33,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,23,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,24,35,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,16,24,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,15,25,35,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,17,25,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,20,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,18,26,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,17,21,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,15,19,26,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,18,22,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,28,32,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,19,23,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,29,33,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,16,18,24,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,20,28,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,16,19,25,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,21,29,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,44,45,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,22,30,},
{1,2,3,4,5,6,7,8,9,10,11,12,14,44,46,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,23,31,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,16,28,35,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,24,32,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,17,29,35,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,25,33,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,20,32,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,26,34,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,20,25,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,22,34,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,18,20,26,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,21,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,22,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,20,22,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,17,19,21,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,22,23,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,18,19,22,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,19,21,23,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,16,18,19,24,26,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,24,25,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,20,21,22,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,24,26,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,44,48,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,26,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,28,33,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,19,25,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,18,28,34,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,28,29,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,30,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,28,30,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,38,46,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,30,31,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,20,31,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,19,29,31,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,19,21,31,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,32,33,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,18,19,22,31,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,32,34,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,42,50,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,34,35,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,24,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,38,50,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,19,25,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,35,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,24,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,19,21,35,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,21,25,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,38,39,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,22,26,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,20,22,24,30,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,23,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,40,41,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,20,21,22,26,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,40,42,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,20,21,23,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,42,43,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,44,49,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,20,24,26,34,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,18,44,50,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,44,45,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,28,32,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,44,46,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,29,33,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,22,24,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,30,34,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,23,25,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,31,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,48,49,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,20,21,30,34,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,48,50,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,20,21,31,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,22,28,31,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,20,21,22,28,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,23,29,31,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,20,21,23,29,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,36,51,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,36,40,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,19,37,51,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,37,41,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,22,32,35,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,38,42,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,20,23,33,35,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,39,43,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,22,32,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,20,22,26,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,23,33,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,20,23,27,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,22,23,34,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,20,28,29,30,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,23,27,31,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,24,25,34,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,44,48,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,45,49,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,26,27,34,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,46,50,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,24,25,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,25,26,27,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,24,26,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,20,30,34,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,26,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,21,28,33,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,21,23,25,27,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,22,28,34,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,28,29,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,21,30,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,28,30,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,21,23,29,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,30,31,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,25,32,33,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,24,28,32,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,26,32,34,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,32,33,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,25,34,35,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,22,32,34,},
{1,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19,20,38,58,},
{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,34,35,},
};
int main()
{
    freopen("nonequal.in","r",stdin);
    freopen("nonequal.out","w",stdout);
    for(int i=1;i<=300;i++) if(i==1||i==2||i==4||i==8) grundy[i]=0; else grundy[i]=++tot;
    scanf("%d",&n);
    if(grundy[n]==0) puts("lose");
    else
    {
        puts("win");
        for(auto x:ans[grundy[n]-1]) printf("%d ",x);
        puts("");
    }
    return 0;
}
