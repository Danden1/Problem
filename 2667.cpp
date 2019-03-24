#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	char map[25][25];
	int ret[625] = {0};
	int n, idx= -1;
	queue<pair<int,int> > q;
	bool visited[25][25] = {0};
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};

	cin >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) cin >> map[i][j];
	}

	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(visited[i][j] || map[i][j] == '0') continue;
			
			idx+=1;
			q.push({i,j});
			visited[i][j] = 1;
			ret[idx] =0;
			
			while(!q.empty()){
				int x = q.front().second, y = q.front().first;
				q.pop();
				ret[idx] += 1;
				
				for(int k = 0; k < 4; k++){
					int xx = x + dx[k], yy = y + dy[k];
					
					if(xx >= n || xx < 0 || yy >=n || yy < 0) continue;
					if(visited[yy][xx] || map[yy][xx] == '0') continue;
					
					
					q.push({yy,xx});
					visited[yy][xx] = 1;
				}
			}
		}
	}
	
	sort(ret, ret+idx+1);
	
	cout << idx+1 << '\n';
	for(int i = 0; i <= idx; i++)
		cout << ret[i] << '\n';
}
