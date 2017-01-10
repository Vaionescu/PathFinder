#include <cstdio>
#include <queue>
using namespace std;
struct Step {
	int y, x, s;
} c, t;
queue<Step> q;
/**
 0  = free
 -1 = wall
 -2 = destination
 1..= step number
*/
int world[1001][1001];
int dvy[] = {	-1,	-1,	0,	1,	1,	1,	0,	-1};
int dvx[] = {	0,	1,	1,	1,	0,	-1,	-1,	-1};
int main() {
	freopen("input.dat", "r", stdin);
	freopen("output.dat", "w", stdout);
	int n, m, k, yd, xd, yp, xp, yw, xw, ts = -1;
	scanf("%d%d%d%d%d%d%d", &n, &m, &k, &yp, &xp, &yd, &xd);
	world[yd][xd] = -2;
	c.y = yp;
	c.x = xp;
	c.s = 1;
	for(int i = 0; i < k; i++) {
		scanf("%d%d", &yw, &xw);
		world[yw][xw] = -1;
	}
	t.s = 1;
	for(int d = 0; d < 8; d++) {
		t.y = c.y + dvy[d];
		t.x = c.x + dvx[d];
		if(t.y > 0 && t.y <= n &&
				t.x > 0 && t.x <= m &&
				world[t.y][t.x] == 0) {
			world[t.y][t.x] = 1;
			q.push(t);
		}
	}
	while(!q.empty()) {
		c = q.front();
		q.pop();
		t.s = c.s + 1;
		for(int d = 0; d < 8; d++) {
			t.y = c.y + dvy[d];
			t.x = c.x + dvx[d];
			if(t.y > 0 && t.y <= n &&
					t.x > 0 && t.x <= m &&
					(world[t.y][t.x] == 0 || world[t.y][t.x] > t.s)) {
				world[t.y][t.x] = t.s;
				q.push(t);
			}
		}
	}
	c.y = yd;
	c.x = xd;
	for(int d = 0; d < 8; d++) {
		t.y = c.y + dvy[d];
		t.x = c.x + dvx[d];
		if(t.y > 0 && t.y <= n &&
				t.x > 0 && t.x <= m &&
				(ts == -1 || world[t.y][t.x] < ts)) {
			ts = world[t.y][t.x];
		}
	}
	printf("%d", ts + 1);
	return 0;
}
