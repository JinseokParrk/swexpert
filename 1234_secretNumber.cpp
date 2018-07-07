#include<iostream>
#include <string>
using namespace std;

int main() {
	int T,N;
	int i;
	for (T = 0; T < 10; T++) {
		cin >> N;
		string str;
		getline(cin, str);
		
		i = 0;
		while (i < N) {
			if (str.at(i) == str.at(i + 1)) {
				str.erase(i, 2);
				i--;
				N = N - 2;
				continue;
			}
			i++;
		}

		cout << "#" <<T+1<<str<< endl;
	}
	return 0;
}