
/*
ID: flyzorr1
PROG: numtri
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

#define MAX_NUM = 2000

int R = 0, max_path = 0;
int data[MAX_NUM][MAX_NUM] = {{0,0}}, vis[MAX_NUM][MAX_NUM][200] = {{0,0,0}};
int result[MAX_NUM] = {0};

void dfs(int depth)
{
	if (depth == R)
	{
		int sum = 0;
		REP (i, R+1) sum += result[i];
		ckmax(max_path, sum);
		return;
	}
}

void solve()
{
	dfs(0);
}

int main()
{
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	
	//R (1 <= R <= 1000), the number of rows.
	cin>>R;
	REP(i, R+1) 
	REP(j, i+1) scanf("%d", &data[i][j]);
	
	solve();
	
	printf("%d\n", max_path);
	return 0;
}
