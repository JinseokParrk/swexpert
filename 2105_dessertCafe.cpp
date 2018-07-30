#include<iostream>
#include<cstring>
using namespace std;

// 4<=N<=20
// 디저트 종류 100까찌
// 못먹으면 -1

int maxPathCnt;
int map[21][21];
int visit[21][21];
int dessert[101];
int N;
int oriX, oriY;
int dx[] = {1,1,-1,-1};
int dy[] = {-1,1,1,-1};

void dfs(int x,int y, int w,int depth) {
	int i, j;
	//////////////////re
	dessert[map[x][y]] = 1;
	visit[x][y] = 1;
	for (i = w; i < w+2; i++) {
		//if (i >= 4) { break; }
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
			if (nx == oriX && ny == oriY && visit[nx][ny]==1) {
				if (maxPathCnt < depth) {
					maxPathCnt = depth;
					break;
				}
			}
			if (dessert[map[nx][ny]] == 0 && visit[nx][ny] == 0) {
				dfs(nx, ny, i, depth + 1);
			}
		}
	}
	//////////////////////////
	visit[x][y] = 0;
	dessert[map[x][y]] = 0;
}

int main() {
	int i, j;
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}

		maxPathCnt = -1;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				oriX = i;
				oriY = j;
				dfs(i,j,0,1);
			}
		}

		cout << "#" << t <<" "<<maxPathCnt << endl;
	}

	return 0;
}