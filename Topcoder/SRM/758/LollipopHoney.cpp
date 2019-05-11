#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cnt[MAXN],sum[MAXN][MAXN],dp[MAXN][MAXN],ways[MAXN][MAXN];
vector<int> candies[MAXN];
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b;if(a>=MOD) a-=MOD;}
void upd(int &a,int b) {a=max(a,b);}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
class LollipopHoney {
	public:
	vector <int> count(int K, vector <int> flavor, vector <int> deliciousness) {
        fact[0]=invf[0]=1;
        for(int i=1;i<=50;i++) fact[i]=1LL*fact[i-1]*i%MOD;
        invf[50]=pow_mod(fact[50],MOD-2);
        for(int i=49;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
        n=(int)flavor.size();
        memset(cnt,0,sizeof(cnt));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=50;i++) candies[i].clear();
		for(int i=0;i<n;i++) cnt[flavor[i]]++,candies[flavor[i]].push_back(deliciousness[i]);
        for(int i=1;i<=50;i++)
        {
            sort(candies[i].begin(),candies[i].end(),greater<int>());
            for(int j=1;j<=(int)candies[i].size();j++) sum[i][j]=sum[i][j-1]+candies[i][j-1];
        }
        memset(dp,0,sizeof(dp));
        memset(ways,0,sizeof(ways));
        dp[0][0]=0,ways[0][0]=1;
        for(int i=0;i<50;i++)
        {
            for(int j=0;j<=2*K;j++)
            {
                if(!ways[i][j]) continue;
                //if(n==12&&K==3) printf("%d %d %d %d\n",i,j,dp[i][j],ways[i][j]);
                for(int k=0;k<=min(K,cnt[i+1]);k++)
                {
                    if(sum[i+1][k]+dp[i][j]<dp[i+1][j+k]) continue;
                    int w=1;
                    if(k>0)
                    {
                        int l=k-1,r=l;
                        while(l>0&&candies[i+1][l-1]==candies[i+1][l]) l--;
                        while(r<(int)candies[i+1].size()-1&&candies[i+1][r+1]==candies[i+1][r]) r++;
                        w=comb(r-l+1,k-l);
                    }
                    if(sum[i+1][k]+dp[i][j]==dp[i+1][j+k]) add(ways[i+1][j+k],1LL*w*ways[i][j]%MOD);
                    else if(sum[i+1][k]+dp[i][j]>dp[i+1][j+k])
                    {
                        dp[i+1][j+k]=sum[i+1][k]+dp[i][j];
                        ways[i+1][j+k]=1LL*w*ways[i][j]%MOD;
                    }
                }
            }
        }
        vector<int> ret; ret.clear();
        if(ways[50][2*K]==0) return ret;
        ret.push_back(dp[50][2*K]); ret.push_back(ways[50][2*K]);
        return ret;
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
			int K                     = 1 ;
			int flavor[]              = {1,1,2,2} ;
			int deliciousness[]       = {10,20,30,40} ;
			int expected__[]          = {60, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LollipopHoney().count(K, vector <int>(flavor, flavor + (sizeof flavor / sizeof flavor[0])), vector <int>(deliciousness, deliciousness + (sizeof deliciousness / sizeof deliciousness[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int K                     = 2 ;
			int flavor[]              = {1,1,1,2,2,2} ;
			int deliciousness[]       = {10,10,10,20,20,20} ;
			int expected__[]          = {60, 9 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LollipopHoney().count(K, vector <int>(flavor, flavor + (sizeof flavor / sizeof flavor[0])), vector <int>(deliciousness, deliciousness + (sizeof deliciousness / sizeof deliciousness[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int K                     = 2 ;
			int flavor[]              = {1,1,1,1,1,2};
			int deliciousness[]       = {10,20,30,40,50,60} ;
			int expected__[]          = { };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LollipopHoney().count(K, vector <int>(flavor, flavor + (sizeof flavor / sizeof flavor[0])), vector <int>(deliciousness, deliciousness + (sizeof deliciousness / sizeof deliciousness[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int K                     = 3 ;
			int flavor[]              = {48,33,22,9,37,44,5,49,24,14,45,1} ;
			int deliciousness[]       = {9,1,7,10,7,10,5,1,3,3,4,5} ;
			int expected__[]          = {48, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LollipopHoney().count(K, vector <int>(flavor, flavor + (sizeof flavor / sizeof flavor[0])), vector <int>(deliciousness, deliciousness + (sizeof deliciousness / sizeof deliciousness[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int K                     = 10 ;
			int flavor[]              = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40} ;
			int deliciousness[]       = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} ;
			int expected__[]          = {20, 846527861 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = LollipopHoney().count(K, vector <int>(flavor, flavor + (sizeof flavor / sizeof flavor[0])), vector <int>(deliciousness, deliciousness + (sizeof deliciousness / sizeof deliciousness[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int K                     = ;
			int flavor[]              = ;
			int deliciousness[]       = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = LollipopHoney().count(K, vector <int>(flavor, flavor + (sizeof flavor / sizeof flavor[0])), vector <int>(deliciousness, deliciousness + (sizeof deliciousness / sizeof deliciousness[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int K                     = ;
			int flavor[]              = ;
			int deliciousness[]       = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = LollipopHoney().count(K, vector <int>(flavor, flavor + (sizeof flavor / sizeof flavor[0])), vector <int>(deliciousness, deliciousness + (sizeof deliciousness / sizeof deliciousness[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int K                     = ;
			int flavor[]              = ;
			int deliciousness[]       = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = LollipopHoney().count(K, vector <int>(flavor, flavor + (sizeof flavor / sizeof flavor[0])), vector <int>(deliciousness, deliciousness + (sizeof deliciousness / sizeof deliciousness[0])));
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
