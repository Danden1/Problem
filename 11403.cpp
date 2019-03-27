#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	vector<int> arr[101];
	bool chk[101][101] = {0};
	int sum[101] = {0};
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
					if(chk[i][arr[tmp][j]]) continue;
					if(i == arr[tmp][j]) continue;
					chk[i][arr[tmp][j]] = true;
					chk[arr[tmp][j]][i] = true;
					sum[i] += cnt;
					sum[arr[tmp][j]] += cnt;
					q.push(arr[tmp][j]);
				}
			}
		}
		
		if(sum[idx] > sum[i])
			idx = i;
	}
	
	cout << idx;

}
