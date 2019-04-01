#include <iostream>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
bool num[10000] = { 0 };

void num_set() {

	for (int i = 2; i <= sqrt(9999); i++) {
		if (!num[i]) {
			for (int j = i + i; j <= 9999; j += i)
				num[j] = true;
		}
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	num_set();
	int t;
	cin >> t;

	while (t--) {
		string x, y;
		int cnt = -1;
		bool chk = false;
		queue<string> q;
		bool visited[10000] = { 0 };

		cin >> x >> y;
		q.push(x); visited[atoi(x.c_str())] = true;

		while (!q.empty()) {
			cnt++;
			int size = q.size();
			
			for (int i = 0; i < size; i++) {
				string tmp = q.front(); q.pop();

				if (tmp == y) {
					chk = true; break;
				}

				for (int j = 0; j < 4; j++) {
					for (int k = 0; k <= 9; k++) {
						string dtmp = tmp;
						dtmp[j] = k + 48;
						if (visited[atoi(dtmp.c_str())]) continue;
						if (num[atoi(dtmp.c_str())]) continue;
						if (atoi(dtmp.c_str()) < 1000) continue;
						q.push(dtmp);
						visited[atoi(dtmp.c_str())] = true;
					}
				}

			}
			if (chk) break;
		}

		if (chk) cout << cnt << endl;
		else    cout << "Impossible" << endl;
	}

}
