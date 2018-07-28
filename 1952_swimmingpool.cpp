#include<iostream>
#include<algorithm>
using namespace std;

int dayF, monF, tmonF, yearF;
int plan[12];
int minFee;

void dfs(int depth,int sum) {
	int i, j;
	if (depth > 11) {
		minFee = (minFee > sum) ? sum : minFee;
		return;
	}
	if (plan[depth] > 0) {
		dfs(depth + 1, sum + plan[depth] * dayF);
		dfs(depth + 1, sum + monF);
		dfs(depth + 3, sum + tmonF);
	}
	else {
		dfs(depth + 1, sum);
	}
}

int main() {
	int T;
	int i,j;
	cin >> T;
	for (i = 1; i <= T; i++) {
		cin >> dayF >> monF >> tmonF >> yearF;
		for (j = 0; j < 12; j++) {
			cin >> plan[j];
		}
		minFee = yearF;
		
		////////////////
		dfs(0, 0);
		/////////////////

		printf("#%d %d\n", i,minFee);
	}

	return 0;
}