#include <iostream>
#include <queue>
using namespace std;
int map[1000][1000];
int n,m;

bool chk(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(map[i][j] == 0) return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	queue<pair<int,int> > q;
	bool visited[1000][1000] = {0};
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};
	int day = -1;
	cin >> m >> n;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> map[i][j];
			if(map[i][j] == 1){
				visited[i][j] = 1;
				q.push({i,j});
			}
		}
	}
	
	if(!chk()){
		cout << 0;
		return 0;
	}
	
	while(!q.empty()){
		int size = q.size();
		day +=1;
		for(int i = 0; i < size; i++){
			int x = q.front().second, y = q.front().first;
			q.pop();
			
			for(int j = 0; j < 4; j++){
				int xx = x + dx[j], yy = y + dy[j];
				if(xx >= m || yy >= n || xx < 0 || yy < 0) continue;
				if(visited[yy][xx] || map[yy][xx] == -1) continue;
				visited[yy][xx] = true;
				map[yy][xx] = 1;
				q.push({yy,xx});	
			}
		}
	}
	
	if(chk()) cout << -1;
	else	cout << day;
}
