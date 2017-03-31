#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main() {
	int N;
	string S;
	string tmp = "";
	vector <pair<int, string>> v;
	bool check = false, count = false;
	
	scanf("%d", &N);
	tmp = "";
	
	for (int i = 0; i < N; i++) {
		cin >> S;

		for (int k = 0;k < S.length();k++) {
			if (isdigit(S[k])) {
				if (S[k] == '0' && (!(check))) {	//앞자리 0인거 구별 하기 위해서.
					
					count = true;
					if (k == S.length() - 1 && !(check)) {
						v.push_back(make_pair(1,"0"));
						count = false;
					}
					continue;
				}

				tmp += S[k];
				check =	true;
				count = false;

				if (k == S.length()-1 && check ) {	//맨 마지막인 경우
					v.push_back(make_pair(tmp.length(),tmp));
					tmp = "";
					check = false;
					count = false;
				}
				
			}
			
			else {
				if (check) {	//숫자 넣기.
					v.push_back(make_pair(tmp.length(),tmp));
					tmp = "";
				}
				else if (count && tmp.length() == 0) {	//전부 0인경우
					v.push_back(make_pair(1,"0"));
					count = false;
				}
				check = false;
			}
		}
	
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << '\n';
	}

}