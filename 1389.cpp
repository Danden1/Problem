#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	vector<int> arr[101];
	int sum[102][102] = {0};
	int idx = 1;
	int n,m,t1,t2;
	
	cin >> n >> m;
	
	for(int i = 1; i <= m; i++){
		cin >> t1 >> t2;
		arr[t1].push_back(t2);
		arr[t2].push_back(t1);
	}
	
	for(int i = 1; i <= n; i++){
		queue<int> q;
		int cnt = 0;
		q.push(i);
		
		while(!q.empty()){
			int q_size = q.size();
			cnt +=1;
			for(int k = 0; k < q_size; k++){
				int tmp = q.front(); q.pop();
				for(int j = 0; j < arr[tmp].size(); j++){
					if(sum[i][arr[tmp][j]] != 0) continue;
					if(i == arr[tmp][j]) continue;
					sum[i][arr[tmp][j]] = cnt;
					q.push(arr[tmp][j]);
				}
			}
		}
		
		for(int j = 0; j <= n; j++)
			sum[i][101] += sum[i][j];
		if(sum[idx][101] > sum[i][101])
			idx = i;
	}
	
	cout << idx;

}
