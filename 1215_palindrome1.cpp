#include<iostream>
#include<cstring>
using namespace std;

// (1,1) 부터 4방향으로 testLen만큼 검사

/*
4
CBBCBAAB
CCCBABCB
CAAAACAB
BACCCCAC
AABCBBAC
ACAACABC
BCCBAABC
ABBBCCAA
*/
// #1 12

char map[9][9];
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,1,-1 };

int main(){
	int testLen;
	int i,j;
	int T=0;
	while (T<10) {
		int cnt = 0;
		cin >> testLen;
		for (i = 1; i <= 8; i++) {
			cin >> map[i] + 1;
		}

		for (int x = 1; x <= 8; x++) {
			for (int y = 1; y <= 8; y++) {
				for (i = 0; i < 4; i++) {
					int palcnt = 0;
					//int visitcnt = 0;
					for (j = 0; j < testLen / 2; j++) {
						int nx = x + dx[i] * (testLen - 1 - j);
						int ny = y + dy[i] * (testLen - 1 - j);
						if (nx >= 1 && nx <= 8 &&
							ny >= 1 && ny <= 8 ) {
							if (map[x + dx[i] * j][y + dy[i] * j] == map[nx][ny]) {
								palcnt++;
						//		visitcnt = visit[x + dx[i] * j][y + dy[i] * j] + visit[nx][ny];
							}
							else break;
							if (palcnt == testLen / 2) {
								cnt++;
								/*
								for (int k = 0; k < testLen; k++) {
									visit[x+k*dx[i]][y+k*dy[i]] = 1;
								}
								*/
							}
						}
					}
				}
			}
		}
		printf("#%d %d\n",++T, cnt/2);
	}
	
	return 0;
}