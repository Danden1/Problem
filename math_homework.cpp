#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
unsigned long long to(string str, int len) {
	unsigned long long x = 1, n = 0;
	for (int i = 1; i <= len; i++) {	
		n += (str[len-i] - '0')*x;
		x *= 10;
	
	}
	return n;
}
int main() {
	int N, count = 0;
	string S;
	string tmp;
	vector <unsigned long long> v;
	bool check = false;
	scanf("%d", &N);
	tmp = "";
	for (int i = 0; i < N; i++) {
		cin >> S;

		for (int k = 0; k < S.length(); k++) {
			if (isdigit(S[k])) {
				tmp += S[k];
				check = true;
				if (k == S.length() - 1) {
					count += 1;
					v.push_back(to(tmp, tmp.length()));
					tmp = "";
					check = false;
				}

			}

			else {
				if (check) {
					count += 1;
					v.push_back(to(tmp, tmp.length()));
					tmp = "";
				}
				check = false;
			}
		}

	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%llu\n", v[i]);
	}

}