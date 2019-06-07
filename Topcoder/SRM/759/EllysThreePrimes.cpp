#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
bool check(int x,int y,int z,vector<int> &sums)
{
    for(int i=0;i<5;i++)
    {
        int sum=0;
        sum+=x%10; sum+=y%10; sum+=z%10;
        x/=10; y/=10; z/=10;
        if(sum!=sums[i]) return false;
    }
    return true;
}
bool flag;
vector<int> ans;
vector<vector<int> > v[6];
void dfs(int now,int x,int y,int z,int mult,vector<int> &sums)
{
    if(flag) return;
    if(now==5) 
    {
        ans.push_back(x); ans.push_back(y); ans.push_back(z);
        flag=true;
        return;
    }
    for(int i=(now==4?1:0);i<10;i++)
        for(int j=(now==4?1:0);j<10;j++)
            for(int k=(now==4?1:0);k<10;k++)
            {
                if(i+j+k!=sums[now]) continue;
                if(!(v[now+1][i*mult+x].size())) continue;
                if(!(v[now+1][j*mult+y].size())) continue;
                if(!(v[now+1][k*mult+z].size())) continue;
                dfs(now+1,i*mult+x,j*mult+y,k*mult+z,mult*10,sums);
            }
}
class EllysThreePrimes {
	public:
	vector <int> getPrimes(vector <int> sums) {
		int p=sieve(100000);
        v[0].resize(1); v[1].resize(10); v[2].resize(100); v[3].resize(1000); v[4].resize(10000),v[5].resize(100000);
        for(int i=0;i<p;i++) 
        {
            if(prime[i]<10000) continue;
            v[0][0].push_back(prime[i]);
            v[1][prime[i]%10].push_back(prime[i]);
            v[2][prime[i]%100].push_back(prime[i]);
            v[3][prime[i]%1000].push_back(prime[i]);
            v[4][prime[i]%10000].push_back(prime[i]);
            v[5][prime[i]].push_back(prime[i]);
        }
        ans.clear(); flag=false;
        dfs(0,0,0,0,1,sums);
        return ans;
	}
};
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int sums[]                = {19, 12, 15, 11, 14};
			int expected__[]          = {20533, 87119, 44987 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int sums[]                = {22, 19, 3, 8, 23};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int sums[]                = {13, 17, 0, 25, 20};
			int expected__[]          = {27011, 99083, 99089 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int sums[]                = {11, 12, 13, 14, 15};
			int expected__[]          = {47221, 23789, 94421 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int sums[]                = {14, 27, 6, 12, 15};
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int sums[]                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int sums[]                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int sums[]                = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = EllysThreePrimes().getPrimes(vector <int>(sums, sums + (sizeof sums / sizeof sums[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
