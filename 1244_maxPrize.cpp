#include <iostream>
#include <string>
using namespace std;
// 정수 자리수 최대 6자리 

void dfs(int idx, int depth) {
	int i, j;

	for(i = idx; i<)
}

int main() {
	int T, N;
	string Card;
	int i;
	cin >> T;
	for (i = 1; i <= T; i++) {
		int temp;
		int maxNum;
		cin >> Card >> N;

		//temp = atoi(Card.c_str());
		temp = stoi(Card);
		// 6자리로 만들수있는 최대 자리수 : 6*5*4*3*2*1 = 720

		printf("#%d %d\n", i, temp);
	}
	return 0;
}





/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

string num;
int check[1000000];
int len, N, ans;

void dfs(int idx, int depth)
{
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		temp += pow(10, len - i - 1)*(num[i] - '0');
	}

	if (depth == N)
	{
		ans = max(temp, ans);
		return;
	}
	if (check[temp] == 1)return;

	check[temp] = 1;

	for (int i = idx; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			swap(num[i], num[j]);
			dfs(i, depth + 1);
			swap(num[j], num[i]);
		}
	}
}

int main()
{
	int Tc;
	cin >> Tc;
	for (int t = 1; t <= Tc; t++) {
		cin >> num;
		cin >> N;
		len = num.size();

		dfs(0, 0);

		printf("#%d %d\n", t, ans);

		memset(check, 0, sizeof(check));
		ans = 0;
	}
	return 0;
}
*/