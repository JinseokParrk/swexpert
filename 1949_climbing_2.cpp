#include<iostream>
using namespace std;
// 3<=N<=8, 1<=K<=5
// 지형 : 1~20
// 가장높은 봉우리 : 5개
// 지형을 깎아 1보다 작게 만드는 경우 가능

int N, K;
int map[9][9];
int visit[9][9];
int pathCnt;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };


void printarry(int(*arr)[9]) {
	int i, j;
	printf("-----------------\n");
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}


void dfs(int x,int y,int depth) {
	int i, j;
	for (i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && nx <= N && ny > 0 && ny <= N && visit[nx][ny]==0) {
			if (map[x][y] > map[nx][ny]) {
				visit[nx][ny] = 1;
				dfs(nx, ny, depth + 1);
				visit[nx][ny] = 0;
			}
			else if(map[x][y]<=map[nx][ny]){
				if (pathCnt < depth) {
					//visit[nx][ny] = 0;
					pathCnt = depth;
					printf("(%d,%d) (%d,%d)\n", x, y,nx,ny);
				}
			}
		}
	}
}

int main() {
	int T;
	int i, j, h;
	cin >> T;
	for (i = 1; i <= T; i++) {
		cin >> N >> K;
		int maxNum = 0;
		for (j = 1; j <= N; j++) {
			for (h = 1; h <= N; h++) {
				cin >> map[j][h];
				if (maxNum <= map[j][h]) {
					maxNum = map[j][h];  //높은 봉우리 값
				}
			}
		}
		pathCnt = 1;
		
	//	memset(visit, 0, sizeof(visit));
		printf("----------------------\n");
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				for (int dep = K; dep >= 0; dep--) {
					map[a][b] -= dep;
					for (j = 1; j <= N; j++) {
						for (h = 1; h <= N; h++) {
							if (map[j][h] == maxNum) {  //높은 봉우리에서만 검사
								visit[j][h] = 1;
								dfs(j, h, 1);
								visit[j][h] = 0;
							}							
						}
					}
					map[a][b] += dep;
				}
			}
		}
		printf("#%d %d\n", i, pathCnt);
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}