#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int visit[1000000]; // 자릿수(6자리) 만큼 체크
int maxNum;

void dfs(string &str,int idx, int depth, int size) {
	int i, j, temp;
	//temp = atoi(Card.c_str());
	temp = stoi(str);
	if (depth == 0) {
		maxNum = max(temp, maxNum);
		return ;
	}
	if (visit[temp] == 1) { return; }
	visit[temp] = 1;

	for (i = idx; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			swap(str[i], str[j]);
			dfs(str, idx, depth - 1, size);
			swap(str[i], str[j]);
		}
	}
}

int main() {
	int T, N;
	string Card;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int stringLength;
		cin >> Card >> N;

		stringLength = Card.size();
		
		dfs(Card, 0, N, stringLength);
		
		printf("#%d %d\n", i, maxNum);

		memset(visit, 0, sizeof(visit));
		maxNum = 0;
	}
	return 0;
}
