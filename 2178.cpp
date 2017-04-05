#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <stdlib.h>
using namespace std;

int bfs(vector <vector<int> > map, int n, int m) {
	int dir[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0, - 1 } };
	int x, y, count;
	queue <tuple<int, int, int> > qu;

	qu.push(make_tuple(0, 0, 1));
	count = get<2>(qu.front());

	while (!qu.empty()) {
		tuple<int, int, int> tmp = qu.front();
		x = get<0>(qu.front()); y = get<1>(qu.front()); count = get<2>(qu.front());
		map[y][x] = 0;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dir_x = get<0>(tmp) + dir[i][1], dir_y = get<1>(tmp) + dir[i][0]; count = get<2>(tmp);

			if (dir_x < 0 || dir_x >= m || dir_y <0 || dir_y >= n) continue;

			if ((dir_x == m - 1) && (dir_y == n - 1)) {
				return count + 1;
			}

			if (map[dir_y][dir_x] == 1) {
				map[dir_y][dir_x] = 0;
				qu.push(make_tuple(dir_x, dir_y, count + 1));
			}

		}
		
	}
	return count;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<int>> map(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	}

	printf("%d\n", bfs(map, n, m));


}