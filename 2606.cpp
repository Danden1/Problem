#include <iostream>
#include <queue>
using namespace std;

int map[100][100][100];
int h,n,m;

bool chk(){
	for(int i = 0; i < h; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				if(map[i][j][k] == 0) return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	bool visited[100][100][100] = {0};
	int dz[6] = {1,-1,0,0,0,0};
	int dy[6] = {0,0,1,-1,0,0};
	int dx[6] = {0,0,0,0,1,-1};
	queue<pair<int,pair<int,int> > > q;
	int day = -1;
	
	cin >> m >> n >> h;
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				cin >> map[i][j][k];
				if(map[i][j][k] == 1){
					q.push({i,{j,k}});
					visited[i][j][k] = true;
				}
			}
		}
	}
	
	if(!chk()){
		cout << 0;
		return 0;
	}
	
	while(!q.empty()){
		int size = q.size();
		day+=1;
		
		for(int i = 0; i < size; i++){
			int x = q.front().second.second, y = q.front().second.first, z = q.front().first;
			q.pop();
			for(int j = 0; j < 6; j++){
				int xx = x + dx[j], yy = y + dy[j], zz = z + dz[j];
				if(xx >= m || yy >= n || zz >= h || xx < 0 || yy < 0 || zz < 0) continue;
				if(visited[zz][yy][xx] || map[zz][yy][xx] == -1) continue;
				visited[zz][yy][xx] = true;
				map[zz][yy][xx] = 1;
				q.push({zz,{yy,xx}});
			}
		}
		
	}
	
	if(chk())	cout << -1;
	else cout << day;
	
}
