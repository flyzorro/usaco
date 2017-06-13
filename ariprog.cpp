
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

#define MAX_NUM 200000

int N = 0, M = 0, max_num = 0, a = 0, b = 0, k = 0;
vector<ipair> result;
int vis[MAX_NUM] = {0};
int hashset_num[MAX_NUM] = { 0 };
int num_set[MAX_NUM] = { 0 };



void dfs(int a, int b, int depth)
{
	if (depth >= N )
	{
		if (find(ALL(result),MP(b,a)) == result.end()) result.push_back(MP(b, a));
		return;
	}

	//avoid duplicate visit
	if ( hashset_num[a+b*depth])
	{
		
		dfs(a, b, depth + 1);
		
	}
}

int main()
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);

	//N (3 <= N <= 25), the length of progressions for which to search
	//M (1 <= M <= 250), an upper bound to limit the search to the bisquares with 0 <= p,q <= M
	cin >> N >> M;
	max_num = M*M;

	REP(i, M + 1)
		REP(j, M + 1)
	{
		int sum = sqr(i) + sqr(j);
		if (!hashset_num[sum])
		{
			hashset_num[sum] = 1;
			num_set[k++] = sqr(i) + sqr(j);
		}
		
	}

	//a must be combination of sqr(i) +sqr(j)
	int aa = 0;
	REP(i, k+1)
	{
		aa = num_set[i];
		FOR(j, 1, 2 * max_num - aa + 1)
		{
			if (aa + (N-1)*j <= 2*sqr(M)) dfs(aa, j, 0);			
		}
			
	}
		
	sort(ALL(result));
	for (auto p : result)
	{
		printf("%d %d\n", p.second, p.first);
	}

	if (result.empty()) printf("NONE\n");
	return 0;
}