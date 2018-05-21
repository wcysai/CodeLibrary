#include <iostream>
#include <iomanip>
using namespace std;
#define MAX_A 1000
#define MAX_N 1000 + 16
int N;
double A, B, H[MAX_N];
 
bool C(const double& mid)
{
	H[1] = mid;
	for (int i = 2; i < N; ++i)
	{
		H[i] = 2 * H[i - 1] + 2 - H[i - 2];
		if (H[i] < 0)
		{
			return false;
		}
	}
	B = H[N - 1];
	return true;
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> N >> A;
	H[0] = A;
	double lb = -1, ub = MAX_A + 16;
	for (int i = 0; i < 100; ++i)
	{
		double mid = (ub + lb) / 2;
		if (C(mid))
		{
			ub = mid;
		}
		else
		{
			lb = mid;
		}
	}
	cout << fixed << setprecision(2) << B << endl;
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}
///////////////////////////End Sub//////////////////////////////////