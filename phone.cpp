#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

int main() {
	int t,n,check;
	vector <pair<int, string>>  v(10000);
	scanf("%d", &t);

	for (int i = 0; i < t; i ++) {
		scanf("%d", &n);
		check = 1;

		for (int j = 0; j < n; j++) {
			cin >> v[j].second;
			v[j].first = v[j].second.length();
		}

		sort(v.begin(), v.begin() + n);
		
		for (int j = 0; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				if (strncmp(v[j].second.c_str(), v[k].second.c_str(), v[j].first)==0) {
					printf("No\n");
					check = 0;
					break;
				}
			}
			if (!check)
				break;
		}

		if (check)
			printf("Yes\n");
		
	}

}