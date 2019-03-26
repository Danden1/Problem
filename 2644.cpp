#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100];
bool visited[100] = {0};
bool chk = 0;

void dfs(int start, int target, int ret){
	if(start == target)	{cout << ret; chk = true;}
	
	for(int i = 0; i  <v[start].size(); i++){
		int tmp = v[start][i];
		
		if(visited[tmp]) continue;
		visited[tmp] = true;
		dfs(tmp,target,ret+1);
	}

}

int main(){
	int target1,target2,n,m,x,y;
	
	cin >> n >> target1 >> target2 >> m;
	
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(target1,target2,0);
	if(!chk) cout << -1;

}
