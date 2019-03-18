#include <iostream>
#include <queue>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	int t;
	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	
	cin >> t;
	
	while(t--){
		char map[100][100];
		int n,m;
		pair<int,int> start;
		cin >> n >> m;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> map[i][j];
				if(map[i][j] == 'S')  start = {i,j};
			}
		}
		
		queue<pair<int,int> > q;
		bool visited[100][100] = {0};
		bool check_goal = 0;
		int count = 0;
		q.push(start);
		
		while(!q.empty() && !check_goal){
			int size = q.size();
			count++;
			
			for(int i = 0; i < size; i++){
				int x = q.front().second, y = q.front().first;
				q.pop();
				
				for(int i= 0; i  < 4; i++){
					int xx = x  + dx[i], yy = y+dy[i];
					
					if(xx < 0 || yy < 0 || xx >= m || yy >= n) continue;
					if(visited[yy][xx] || map[yy][xx] == '#') continue;
					if(map[yy][xx] == 'E'){
						check_goal = true;
						break;
					}
					q.push({yy,xx});
					visited[yy][xx] = true;
				}
			}
		}
		if(check_goal) cout << count << endl;
		else		  cout << -1 << endl;
	}	
}
