#include<iostream>
//#include<cstring>
using namespace std;

int numButton[10];
int X; // 1~1,000,000
char numCh[8];
int sumButtonNum;

void intToChar(int num,char *str) {
	int i;
	int temp;
	i = 0;
	temp = num;
	while (temp) {
		str[i++] = (temp % 10)+'0';
		temp = temp / 10;
	}
	int len = i;
	
	for (i = 0; i < len / 2; i++) {
		temp = str[i];
		str[i] = str[len-1-i];
		str[len - 1 - i] = temp;
	}
	str[len] = NULL;
}

bool checkNumButton(char *ch) {
	int i;
	int temp;
	int len;
	len = strlen(ch);
	for (i = 0; i < len; i++) {
		temp = ch[i] - '0';
		if (!numButton[temp]) {
			return false;
		}
	}
	return true;
}

void dfs(int x,int sumButtonLen) {
	int i;
	int temp;
	char num1[8];
	char num2[8];
	printf("-> X = %d , sumButtonLen = %d \n", x,sumButtonLen);
	for (i = 2; i < x/i; i++) {
		if (x % i == 0) {
			printf("%d * %d\n", i, x / i);
			// i 와 x/i가 둘다 버튼에 있는지 확인
			intToChar(i, num1);
			intToChar(x / i, num2);
			if (checkNumButton(num1) && checkNumButton(num2)) {
				//길이 저장				
				temp = sumButtonLen + strlen(num1) + strlen(num2) + 1;
				printf("정답 : %d\n",temp);
				if (temp < sumButtonNum) {					
					sumButtonNum = temp;
				}

			}
			else {
				/*
				if (!checkNumButton(num1) && checkNumButton(num2)) {
					printf("-> num1 = %s\n", num1);
					dfs(i, strlen(num2)+1);
				}
				else*/ if (checkNumButton(num1) && !checkNumButton(num2)) {
					printf("-> num2 = %s\n", num2);
					dfs(x/i,sumButtonLen+strlen(num1)+1);
				}
			}
		}
	}
}

int main() {
	int t, T;
	int i;
	cin >> T;
	for (t = 1; t <= T; t++) {
		for (i = 0; i < 10; i++) {
			cin >> numButton[i];
		}
		cin >> X;
		
		sumButtonNum = 100;

		intToChar(X, numCh);		
		if (checkNumButton(numCh)) {
			sumButtonNum = strlen(numCh);
		}
		else {
			dfs(X,0);
		}

		if (sumButtonNum == 100) {
			sumButtonNum = -2;
		}
		printf("#%d %d\n", t,sumButtonNum+1);
	}
	return 0;
}