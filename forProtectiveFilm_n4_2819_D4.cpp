#include<iostream>
using namespace std;

int map[4][4]; //0~9
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int sum;

void dfs(int x,int y,int depth,int outputNum,int *p) {
	outputNum += (map[x][y] * depth);
	if (depth == 0) {
		if (!p[outputNum]) {
			p[outputNum] = 1;
			sum++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
			dfs(nx, ny, depth / 10, outputNum,p);
		}
	}
}

int main() {
	int t, T;
	int i, j;
	cin >> T;
	for (t = 1; t <= T; t++) {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}

		int *p = new int[10000001]();
		sum = 0;

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				dfs(i, j, 1000000, 0, p);
			}
		}
		
		delete[] p;

		printf("#%d %d\n", t,sum);
		
	}
	return 0;
}