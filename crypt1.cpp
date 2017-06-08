/*
ID: flyzorr1
PROG: crypt1
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

char input[maxn];
int hashtbl[maxn] = { 0 };
int prime_hashtbl[maxn] = {0};

bool isPrime (int i)
{
	return (i == 3 || i == 5 || i == 7 || i == 2);
}
bool in_hash_table(int hash_table[],int n)
{
	int count = n;
	while (count)
	{
		//check every digit of a number
		if (hash_table[count % 10] == 0) return false;

		count -= count % 10;
		count /= 10;
	}

	return true;
}

bool ok(int i, int j)
{
	//product1/2 should be <1000
	//product1 / 2 should be also in hashtable
	int product1 = i * (j % 10), prodcut2 = i * (j / 10);
	return  (product1 < 1000 && prodcut2 < 1000) 
		&& in_hash_table(hashtbl, product1) 
		&& in_hash_table(hashtbl, prodcut2);

}

void solve()
{
	int count = 0;
	//abc,de should be in hash table
	FOR(i, 100, 999)
	{
		if (!in_hash_table(prime_hashtbl,i)) continue;
		FOR(j, 10, 99)
		{
			if (!ok(i, j)) continue;
			if (!in_hash_table(prime_hashtbl,j) || !in_hash_table(hashtbl,i*j)) continue;

			count++;
		}
	}

	cout << count << endl;

}

int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);

	int N = 0;
	cin >> N;
	//get input digits
	int j = 0;
	REP(i, N)
	{
		cin >> j;
		hashtbl[j] += 1;
		if (isPrime(j)) prime_hashtbl[j] += 1;
	}
	
	solve();

	return 0;
}
