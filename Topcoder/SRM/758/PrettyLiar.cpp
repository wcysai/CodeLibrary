#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int n,f[MAXN][MAXM],g[MAXN][MAXM];//f: kaede, g:kanade
int fact[MAXN];
int tmp[MAXN][MAXM];
int sum[MAXN][MAXM];
class PrettyLiar {
	public:
	int count(int S, vector <int> kaede, vector <int> kanade) {
        fact[0]=1;
        for(int i=1;i<=100;i++) fact[i]=1LL*fact[i-1]*i%MOD;
		memset(f,0,sizeof(f)); memset(g,0,sizeof(g)); memset(sum,0,sizeof(sum));
        f[0][0]=g[0][0]=1;
        n=(int)kaede.size();
        for(int i=0;i<n;i++)
            for(int j=n-1;j>=0;j--)
                for(int k=0;k<=100*j;k++)
                {
                    add(f[j+1][k+kaede[i]],f[j][k]);
                    add(g[j+1][k+kanade[i]],g[j][k]);
                }
        for(int i=0;i<=n;i++)
            for(int j=1;j<=10000;j++)
            {
                sum[i][j]=sum[i][j-1];
                add(sum[i][j],f[i][j]);
            }
        int ans=0;
        for(int last=0;last<n;last++)
        {
            int v=kanade[last];
            memset(tmp,0,sizeof(tmp));
            for(int i=0;i<=n;i++)
                for(int j=0;j<=100*i;j++)
                    tmp[i][j]=g[i][j];
            for(int i=0;i<n;i++)
                for(int j=0;j<=100*i;j++)
                    dec(tmp[i+1][j+v],tmp[i][j]);
            for(int round=0;round<n;round++)
            {
                for(int score=0;score<min(100*round+1,S);score++)
                {
                    int l=max(1,S-score-v);
                    int r=min(100*(round+1),S-score-1);
                    if(l>r) continue;
                    int p=sum[round+1][r];
                    dec(p,sum[round+1][l-1]);
                    int q=tmp[round][score];
                    add(ans,1LL*p*q%MOD*fact[round]%MOD*fact[n-round-1]%MOD*fact[round+1]%MOD*fact[n-round-1]%MOD);
                }
            }
        }
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			int S                     = 60;
			int kaede[]               = {10,40} ;
			int kanade[]              = {20,30} ;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = PrettyLiar().count(S, vector <int>(kaede, kaede + (sizeof kaede / sizeof kaede[0])), vector <int>(kanade, kanade + (sizeof kanade / sizeof kanade[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int S                     = 100;
			int kaede[]               = {10,40} ;
			int kanade[]              = {20,30} ;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = PrettyLiar().count(S, vector <int>(kaede, kaede + (sizeof kaede / sizeof kaede[0])), vector <int>(kanade, kanade + (sizeof kanade / sizeof kanade[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int S                     = 10;
			int kaede[]               = {10,40} ;
			int kanade[]              = {20,30} ;
			int expected__            = 0;

			std::clock_t start__      = std::clock();
			int received__            = PrettyLiar().count(S, vector <int>(kaede, kaede + (sizeof kaede / sizeof kaede[0])), vector <int>(kanade, kanade + (sizeof kanade / sizeof kanade[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int S                     = 25;
			int kaede[]               = {6,14} ;
			int kanade[]              = {7,1} ;
			int expected__            = 2;

			std::clock_t start__      = std::clock();
			int received__            = PrettyLiar().count(S, vector <int>(kaede, kaede + (sizeof kaede / sizeof kaede[0])), vector <int>(kanade, kanade + (sizeof kanade / sizeof kanade[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int S                     = 178;
			int kaede[]               = {25,6,14,100,71,49} ;
			int kanade[]              = {17,7,1,100,62,43};
			int expected__            = 240192;

			std::clock_t start__      = std::clock();
			int received__            = PrettyLiar().count(S, vector <int>(kaede, kaede + (sizeof kaede / sizeof kaede[0])), vector <int>(kanade, kanade + (sizeof kanade / sizeof kanade[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int S                     = 1546;
			int kaede[]               = {50,77,74,23,43,4,57,13,50,94,43,72,94,36,20,23,27,7,3,21,16,64,28,20,2,40,92,93,17,94,43,17,1,87,58,67,43,22,99,76,13,10,45,28,2,5,37,26,76,12} ;
			int kanade[]              = {40,93,80,23,20,71,23,14,43,45,38,20,61,84,35,9,85,71,7,21,10,42,23,20,38,73,58,97,32,3,43,99,31,39,33,73,81,3,9,73,17,68,50,27,25,86,22,47,64,8} ;
			int expected__            = 949234178;

			std::clock_t start__      = std::clock();
			int received__            = PrettyLiar().count(S, vector <int>(kaede, kaede + (sizeof kaede / sizeof kaede[0])), vector <int>(kanade, kanade + (sizeof kanade / sizeof kanade[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int S                     = 4;
			int kaede[]               = {1,1,1,1};
			int kanade[]              = {1,1,1,1};
			int expected__            = 576;

			std::clock_t start__      = std::clock();
			int received__            = PrettyLiar().count(S, vector <int>(kaede, kaede + (sizeof kaede / sizeof kaede[0])), vector <int>(kanade, kanade + (sizeof kanade / sizeof kanade[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int S                     = ;
			int kaede[]               = ;
			int kanade[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PrettyLiar().count(S, vector <int>(kaede, kaede + (sizeof kaede / sizeof kaede[0])), vector <int>(kanade, kanade + (sizeof kanade / sizeof kanade[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int S                     = ;
			int kaede[]               = ;
			int kanade[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PrettyLiar().count(S, vector <int>(kaede, kaede + (sizeof kaede / sizeof kaede[0])), vector <int>(kanade, kanade + (sizeof kanade / sizeof kanade[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int S                     = ;
			int kaede[]               = ;
			int kanade[]              = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PrettyLiar().count(S, vector <int>(kaede, kaede + (sizeof kaede / sizeof kaede[0])), vector <int>(kanade, kanade + (sizeof kanade / sizeof kanade[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
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
