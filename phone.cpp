#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

int main() {
	int t, n, check;
	string tmp;
	vector <string>  v(10000);
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		check = 1;

		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}

		sort(v.begin(), v.begin() + n);

		for (int j = 0; j < n-1; j++) {
			tmp = v[j + 1].substr(0, v[j].length());
			if (v[j] == tmp) {
				printf("NO\n");
				check = 0;
				break;

			}
			if (!check)
				break;
		}
		if (check)
			printf("YES\n");
	}
}