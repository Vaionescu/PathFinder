#include <cstdio>
#include <cstdlib>
using namespace std;

const int NMAX = 100;
const int MMAX = 20;

bool Map[NMAX][MMAX], Sol[NMAX][MMAX];
int posCi, posCj, endCi, endCj;
int vdi[4] = { 1, 0, -1, 0};
int vdj[4] = {0, -1, 0, 1};
int n, m;
bool inBounds( int posI, int posJ ) {
	return ( posI >= 0 && posJ >= 0 && posI < n && posJ < m );
}
bool notWall( int posI, int posJ ) {
	return (!Map[posI][posJ] && !Sol[posI][posJ]);
}
void finish() {
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < m; j++ ) {
			if( Sol[i][j] == true ) {
				printf( "1 " );
			} else {
				printf( "0 " );
			}
		}
		printf( "\n" );
	}
	exit( 0 );
}
void solve( int pCi, int pCj ) {
	Sol[pCi][pCj] = true;
	if( pCi == endCi && pCj == endCj ) {
		finish();
	}
	for( int d = 0; d < 4; d++ ) {
		if( inBounds( pCi + vdi[d], pCj + vdj[d] ) ) {
			if( notWall( pCi + vdi[d], pCj + vdj[d] ) ) {
				solve( pCi + vdi[d], pCj + vdj[d] );
			}
		}
	}
	Sol[pCi][pCj] = false;
}

int main() {
	freopen( "data.txt", "r", stdin );
	freopen( "sol.txt", "w", stdout );
	int*x = new int;
	scanf( "%d%d", &n, &m );
	posCi = 0;
	posCj = m - 1;
	endCi = n - 1;
	endCj = 0;
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < m; j++ ) {
			scanf( "%d", x );
			if( *x == 1 ) {
				Map[i][j] = true;
			} else {
				Map[i][j] = false;
			}
		}
	}
	delete x;
	solve( posCi, posCj );
	printf("No solution found!");
	return 0;
}
