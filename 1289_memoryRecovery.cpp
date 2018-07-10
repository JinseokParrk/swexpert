#include <iostream>
#include<cstring>

using namespace std;

char memory[51];
char temp[51];

int main() {
	int T,i,j,k;
	int cnt;
	cin >> T;
	for(i=1;i<=T;i++){
		cnt = 0;
		
		cin >> memory;
		
		for (j = 0; j < strlen(memory); j++) {
			temp[j] = '0';
		}

		for (j = 0; j < strlen(memory); j++) {
			if (memory[j] != temp[j]) {
				if (memory[j] == '1') {
					for (k = j; k < strlen(memory); k++) {
						temp[k] = '1';
					}
				}
				else if (memory[j] == '0') {
					for (k = j; k < strlen(memory); k++) {
						temp[k] = '0';
					}
				}
				cnt++;
			}
		}		
		printf("#%d %d\n", i, cnt);		
	}
	return 0;
}