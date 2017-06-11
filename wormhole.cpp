/*
ID: flyzorr1
PROG: wormhole
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

const int maxn = 100;

#define WORM_HOLE_EDGE 1
#define SAME_Y_EDGE 2

int N = 0;


vector<ipair> wormhole;//vertex
vector<int> wormhole_idx;//vertex

vector<vector<int>> result;

int edges[maxn][maxn] = { { 0,0 } };
int visited[maxn] = { 0 };
int output[maxn] = { 0 };
int total = 0;

int hashset_visited[maxn] = { 0 };

void construct_graph(vector<int> d, int N)
{
	//用edge的值来区分类型，1 表示wormhole产生的edge。 2 表示 Y 值相同产生的edge

	memset(edges, 0, sizeof(edges));
	memset(hashset_visited, 0, sizeof(hashset_visited));

	REP(i, N)
		FOR(j, i + 1, N)
	{
		//注意如果有多个wormhole有相同Y值的情况下，只和最近的wormhole创建一条edge。
		if (wormhole[i].second == wormhole[j].second) { edges[i][j] = SAME_Y_EDGE; break; }
	}

	for (int i = 0; i < N; i += 2) { edges[d[i]][d[i + 1]] = WORM_HOLE_EDGE; edges[d[i + 1]][d[i]] = WORM_HOLE_EDGE; }
	
	/* REP(i, N)
	{
		REP(j, N) { printf("%d ", edges[i][j]); }
		printf("\n\n");
	}  */

}


bool judge(bool entering, int vertex, int &succ)
{
	int childs = 0;
	REP(i, N)
	{
		int value = edges[vertex][i];
		if (value > 0) { childs++; }
	}

	if (entering)
	{
		//if entering status, must walking in +x direction
		if (wormhole[vertex].second == wormhole[succ].second && wormhole[vertex].first < wormhole[succ].first) return true;
	}
	else
	{
		//if leaving status, must walking to wormhole if existed
		if (childs == 1) return true;
		if (edges[vertex][succ] == edges[succ][vertex]) return true;
	}


	return false;
}


bool hasCycle(bool entering, int vertex)
{
	
	REP(i, N)
	{
		int value = edges[vertex][i];

		if (value > 0)
		{
			int succ = i;
			if (!judge(entering, vertex, succ))
				continue;

			if (entering) hashset_visited[succ] += 1;
			if (hashset_visited[succ] >= 2) return true;

			//has valid path ,continue to search
			return hasCycle(!entering, succ);
		}
	}

	return false;
}

bool ok(int cur, int i, vector<int> output)
{
	//for any pair (1,2) (3,4) the start should be in descending order;
	if (cur % 2 == 0 && cur >= 2)
	{
		return wormhole_idx[i] > output[cur - 2];
	}
	//for any pair, end > start
	if (cur % 2 == 1) return wormhole_idx[i] > output[cur - 1];

	return true;// for cur = 0
}

void dfs(int cur, vector<int> output)
{
	if (cur == N)
	{
		result.push_back(output);
		return;
	}


	FOR(j, 0, N)
	{
		if (!visited[j] && ok(cur, j, output))
		{
			visited[j] = 1;
			output.push_back(wormhole_idx[j]);
			dfs(cur + 1, output);
			visited[j] = 0;
			output.pop_back();
		}
	}
}


void solve()
{
	for (auto p : result)
	{
		construct_graph(p, N);
		REP(i, N)
		{
			memset(hashset_visited, 0, sizeof(hashset_visited));
			if (hasCycle(true, i))
			{
				total++;
				break;
			}
		}
	}
	
}


int main()
{
	freopen("wormhole.in", "r", stdin);
	freopen("wormhole.out", "w", stdout);

	cin >> N;

	int x = 0, y = 0;
	REP(i, N) { scanf("%d %d", &x, &y); wormhole.push_back(MP(x, y)); wormhole_idx.push_back(i); }
	sort(ALL(wormhole));

	vector<int> data;
	dfs(0,data);

	solve();

	printf("%d\n", total);
	return 0;
}
