#include<iostream>
#include<cmath>
using namespace std;

int map[21][21];
int N, M;
int maxHome=0;

int search(int x,int y,int K) {
	int i, j, m,n;
	int cnt=0;
	for (i = -(K-1); i < K; i++) {
		for (j = -(K-1); j < K; j++) {
			if ((abs(i) + abs(j)) <= abs(K - 1)) {
				if (x + i > 0 && y + j > 0 && x + i <= N && y + j <= N) {
					if (map[x + i][y + j] == 1) cnt++;
				}
			}
		}
	}
	return cnt;
}

void allCheck() {
	int k,i, j;
	int opCost;
	int revenue;
	int temp;
	for (k = 1; k <= 21; k++) { // K범위 N보다 1크게
		opCost = k * k + (k - 1)*(k - 1);
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				temp = search(i, j, k);				
				revenue = M*temp;
				if (revenue>=opCost) {
					if (maxHome < temp) {
						maxHome = temp;
					}
				}
			}
		}
	}
}

int main() {
	int T;
	int t, i, j;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N >> M;
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}

		allCheck();

		printf("#%d %d\n", t,maxHome);
		maxHome = 0;
	}
	return 0;
}