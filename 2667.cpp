#include <iostream>
#include <algorithm>
using namespace std;

int ret[625] = {0}, n, idx=-1;
bool visited[25][25] = {0};
char map[25][25];

void dfs(int y, int x){
	if(y >= n || y < 0 || x >= n || x < 0 || map[y][x] =='0' || visited[y][x]) return;
	ret[idx]++;
	visited[y][x] = 1;
	dfs(y-1,x), dfs(y+1,x) , dfs(y,x-1), dfs(y,x+1);
}

int main(){
	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(visited[i][j] || map[i][j] == '0') continue;
			idx++;
			dfs(i,j);
			cout << "cnt " <<ret[idx] << endl;
		}
	}
	sort(ret, ret+idx+1);
	
	cout << idx+1 << '\n';
	for(int i = 0; i <= idx; i++)
		cout << ret[idx] << '\n';
}
