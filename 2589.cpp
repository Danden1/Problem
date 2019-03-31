#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	char map[51][51];
	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	int ret = 0;
	int l,w;
	
	cin >> l >> w;
	
	for(int i = 0; i  < l; i++){
		cin >> map[i];
	}
	
	for(int i = 0; i < l; i++){
		for(int j = 0; j < w; j++){
			if(map[i][j] == 'L'){
				int cnt = 0;
				int chk = false;
				queue<pair<int,int> > q;
				bool visited[50][50] = {0};
				q.push({i,j}); visited[i][j] =true;
				
				while(!q.empty()){
					if(chk){
						cnt+=1;
						ret = max(ret, cnt);
					}
					int size = q.size();
					for(int h = 0; h < size; h++){
						int x = q.front().second, y = q.front().first;
						q.pop();
						for(int k = 0; k < 4; k++){
							int xx = x+dx[k], yy = y + dy[k];
							
							if(xx < 0 || yy < 0 || xx >= w || yy >= l) continue;
							if(visited[yy][xx] || map[yy][xx] == 'W') continue;
							visited[yy][xx] = true;
							q.push({yy,xx});
						}
					}
					chk = true;
				}
				
				
			}
		}
	}
	cout << ret;
}
