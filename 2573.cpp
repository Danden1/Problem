#include iostream
#include queue
using namespace std;

int map[300][300] = {0};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m;

bool bfs_chk(){
	int cnt = 0;
	bool visited[300][300] = {0};

	queuepairint,int  q;
	
	for(int i = 0; i  n; i++){
		for(int j = 0; j   m; j++){
			if(cnt =2) return true;
			if(visited[i][j]  map[i][j] == 0) continue;
			cnt+=1;
			q.push({i,j}); visited[i][j] = 1;
			
			while(!q.empty()){
				int x= q.front().second, y = q.front().first;
				q.pop();
				
				for(int k = 0; k  4; k++){
					int xx = x + dx[k], yy = y + dy[k];
					if(yy = n  yy  0  xx = m  xx  0) continue;
					if(map[yy][xx] == 0  visited[yy][xx]) continue;
					q.push({yy,xx}); visited[yy][xx] = 1;
				}
			}
		}
	}
	
	return false;
}

bool chk_zero(){
	for(int i = 0; i  n; i++){
		for(int j = 0; j  m; j++){
			if(map[i][j] != 0) return false;
		}
	}
	return true;
}

int main(){
    ios_basesync_with_stdio(false);
	int y = 0;
	int m_map[300][300] = {0};
	cin  n  m;
	
	for(int i = 0; i  n; i++){
		for(int j = 0; j   m; j++)
			cin  map[i][j];		
	}
	
	while(1){
		if(chk_zero()){ cout  0; break;}
		if(bfs_chk()){cout  y; break;}
		y+=1;
		
		for(int i = 0; i  n; i++){
			for(int j = 0; j  m; j++){
				if(map[i][j] != 0){
					int zero_cnt = 0;
					for(int k = 0; k  4; k++){
						int x = j + dx[k] , y = i + dy[k];
						if(map[y][x] == 0) zero_cnt+=1;
					}
					m_map[i][j] = zero_cnt;
				}
			}
		}
		
		for(int i = 0; i  n; i++){
			for(int j = 0; j  m; j++){
				if(map[i][j] != 0){
					map[i][j] -= m_map[i][j];
					if(map[i][j]  0) map[i][j] = 0;
				}
			}
		}
		
	}
}
