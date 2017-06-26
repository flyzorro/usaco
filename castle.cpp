/*
 *
ID: flyzorr1
PROG:castle 
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

#define MAX_NUM 100

int data[MAX_NUM][MAX_NUM];
int data_cpy[MAX_NUM][MAX_NUM];
int visited[MAX_NUM][MAX_NUM] ;
int M = 0, N = 0;
int size = 0;
int rooms = 0;
int num_of_rooms[MAX_NUM] = {0};

void dfs(int row, int col ,int depth)
{

//	printf("%d %d %d\n",row,col,visited[row][col]);
	//judge the boundary limit
	if (row < 1 || col < 1 || row > M || col > N) {return;}
	if( visited[row][col]) {return;}


	num_of_rooms[depth] = ++size;
	
	visited[row][col] = 1;
	//four bondary graph
	//where can this place go (s/n/w/e)
	int d = data[row][col];
	REP (i,4)
	{

		int j = col, k = row;
		if (0 == (d & (1 << i)))
		{
			if (0 == i) j -=1;
			else if (1 ==i) k -= 1;
			else if (2 ==i) j += 1;
			else if (3 == i) k += 1;

			dfs(k,j,depth);
		}
	}

}

int max_row = 0,max_col = 0,max_direction = 0,max_value =0;
void check_max(int val,int row,int col,int dir)
{
	if (val >= max_value) {max_value = val;max_row = row;max_col = col;max_direction = dir;};
}
void solve()
{
	FOR (i ,1,M+1 )
		FOR (j, 1, N+1) {if (!visited[i][j]) {size = 0;dfs(i, j , ++rooms);}}

	printf("%d\n", rooms);


	sort(num_of_rooms, num_of_rooms+ sizeof(num_of_rooms), greater<int>());
	printf("%d\n", num_of_rooms[0]);

	//search from west to east to see if has wall to the east
	//search from north to south to see if has wall to the south

	memset(visited, 0 ,sizeof(visited));
	FOR (i, 1, M+1)
		FOR(j,1, N+1)
		{
			//if has wall to the east
			if ((data[i][j] & (1<<2))&& j != N)
			{
				data[i][j] -= 4;
				size =0; 
				memset(visited, 0, sizeof(visited));
				dfs(i,j,0);
			//	printf("row=%d,col=%d,E,size=%d\n",i,j,size);
				check_max(size,i,j,0);
				//reset
				data[i][j] += 4;
			}

			if ((data[i][j] & (1<<3))&& i != M)
			{
				data[i][j] -= 8;
				size =0; 
				memset(visited, 0, sizeof(visited));
				dfs(i,j,0);
			//	printf("row=%d,col=%d,N,size=%d\n",i,j,size);

				check_max(size,i,j,1);
				//reset
				data[i][j] += 8;
			}
		}


	char c_dir = (0 == max_direction) ? 'E' : 'N';
	printf("%d\n",max_value);
	printf("%d %d %c\n",max_row,max_col,c_dir);
}

int main()
{
	freopen("castle.in", "r", stdin);
	freopen("castle.out", "w", stdout);

	scanf ("%d %d", &N, &M);

	FOR (i ,1,M+1 )
		FOR (j, 1, N+1)
		scanf("%d", &data[i][j]);


//	FOR (i ,1,M+1 ){
//		FOR (j, 1, N+1)		printf("%d ", data[i][j]);
//		printf("\n");
//	}


	memset(visited, 0, sizeof(visited));
	solve();
	return 0;
}
