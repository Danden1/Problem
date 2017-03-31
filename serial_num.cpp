#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	vector <pair<int,pair<int, string> > > num(N);

	for (int i = 0; i < N; i++) {

		cin >> num[i].second.second;
		num[i].first = num[i].second.second.length();
		num[i].second.first = 0;

		for (int j = 0; j < num[i].first; j++) {
			if (isdigit(num[i].second.second[j]))
				num[i].second.first += num[i].second.second[j] - '0';
		}

	}

	sort(num.begin(), num.begin() + N);

	for (int i = 0; i < N; i++) {
		cout << num[i].second.second << '\n';
	}
}