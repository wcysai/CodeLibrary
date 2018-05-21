#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
 
#define MAX_N 500000
int factor_table[MAX_N + 16];
char name[MAX_N + 16][16];
int  integer[MAX_N + 16];
 
void init_factor_table(int n)
{
	fill(factor_table, factor_table + n + 1, 1);
	for (int i = 2; i <= n; ++i)
	{
		if (factor_table[i] == 1)
		{
			for (int j = i; j <= n; j += i)
			{
				int k = 0;
				for (int m = j; m % i == 0; m /= i, ++k);
				factor_table[j] *= k + 1;
			}
		}
	}
}
 
template <class T>
class BinaryIndexedTree
{
public:
	T bit[MAX_N];
	int size;
 
	BinaryIndexedTree(){}
 
	void init(int size)
	{
		this->size = size;
		memset(bit, 0, sizeof(bit));
	}
 
	T sum(int i)
	{
		int s = 0;
		while (i > 0)
		{
			s += bit[i];
			i -= (i & -i);
		}
		return s;
	}
 
	void add(int i, T v)
	{
		++i;	// 防止如果i是0的话，下面的循环永远不会终止
		while (i <= MAX_N)
		{
			bit[i] += v;
			i += (i & -i);
		}
	}
 
	// 二分搜索真实下标
	T binary_search(int id)
	{
		int lb = 0, ub = size;
		while (ub - lb > 1)
		{
			int mid = (ub + lb) >> 1;
			if (sum(mid) <= id)
			{
				lb = mid;
			}
			else
			{
				ub = mid;
			}
		}
		return lb;
	}
};
 
BinaryIndexedTree<int> bit;	// bit.binary_seach(x)表示当前排序为x的人的初始下标
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, K;
 
	init_factor_table(MAX_N + 16);
	while (cin >> N >> K)
	{
		--K;
		bit.init(N);
 
		for (int i = 0; i < N; ++i)
		{
			scanf("%s %d", name[i], &integer[i]);
			bit.add(i, 1);
		}
 
		int candies = -1, index;
		for (int i = 0; i < N; ++i)
		{
			if (candies < factor_table[i + 1])
			{
				candies = factor_table[i + 1];
				index = K;
			}
			bit.add(K, -1);
			if (i < N - 1)
			{
				int mod = N - i - 1;	// 当前人数
				int id = bit.sum(K) + integer[K] + (integer[K] > 0 ? -1 : 0);	// 下标从0开始
				id = (id % mod + mod) % mod;
				K = bit.binary_search(id);	// K表示下一个站出来的孩子的初始index
			}
		}
 
		printf("%s %d\n", name[index], candies);
	}
 
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}