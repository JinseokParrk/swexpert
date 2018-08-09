#include<iostream>
#include<queue>
#include<utility>
#define INF 999999
using namespace std;

int map[101][101];
int visit[101][101];
int N;
queue<pair<int,int>> q;
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,1,-1 };

void dp() {
	int i, j;
	q.push(make_pair(1, 1));
	visit[1][1] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
				if (visit[nx][ny] > visit[x][y] + map[nx][ny]) {
					visit[nx][ny] = visit[x][y] + map[nx][ny];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	int t, T;
	int i, j;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				scanf_s("%1d", &map[i][j]);
				visit[i][j] = INF;
			}
		}

		dp();

		printf("#%d %d\n", t, visit[N][N]);
	}
	return 0;
}