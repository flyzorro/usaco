
/*
ID: flyzorr1
PROG: ariprog
LANG: C++11
*/


#include <cstdio> 
#include <iostream> 
#include <cmath> 
#include <string> 
#include <list> 
#include <vector> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <set> 
#include <unordered_map> 
#include <map> 
#include <complex> 
#include <queue> 
#include <stack> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <string.h> 

using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef pair<int, int> ipair;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A,B) make_pair(A,B)
const double pi = acos(-1.0);
const double eps = 1e-11;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(a) (a).begin(),(a).end()

template<class T> T sqr(const T &x) { return x*x; }
template<class T> T lowbit(const T &x) { return (x ^ (x - 1))&x; }
template<class T> int countbit(const T &n) { return (n == 0) ? 0 : (1 + countbit(n&(n - 1))); }
template<class T> void ckmin(T &a, const T &b) { if (b<a) a = b; }
template<class T> void ckmax(T &a, const T &b) { if (b>a) a = b; }

int N = 0, M = 0, max_num = 0, a = 0, b = 0;
vector<ipair> result;


bool isSquareSum(int n)
{
	/*REP(i, M + 1)
	REP(j, M + 1)
	{
	if (sqr(i) + sqr(j) == n) return true;
	}

	return false;*/

	for (int i = 0; i < sqrt(n + 0.5) && i <= M; i++)
	{
		int j = sqrt(n - i*i);
		if (j <= M && sqr(i) + sqr(j) == n && i <= j) return true;
	}

	return false;
}


void dfs(int a, int b, int depth)
{
	if (depth >= N)
	{
		result.push_back(MP(b, a));
		return;
	}


	if (isSquareSum(a + b*depth))
	{
		dfs(a, b, depth + 1);
	}
}

int main()
{
	/*freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);*/

	//N (3 <= N <= 25), the length of progressions for which to search
	//M (1 <= M <= 250), an upper bound to limit the search to the bisquares with 0 <= p,q <= M
	cin >> N >> M;
	max_num = M*M;

	REP(i, 2 * max_num + 1)
		FOR(j, 1,2 * max_num - i + 1) dfs(i, j, 0);

	sort(ALL(result));
	for (auto p : result)
	{
		printf("%d %d\n", p.second, p.first);
	}

	if (result.empty()) printf("NONE\n");
	return 0;
}