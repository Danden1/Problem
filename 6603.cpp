#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[13];
int t = 0;

void dfs(int start, vector<int>& v){
	v.push_back(arr[start]);
	if(v.size() == 6){
		for(int i = 0; i < 6; i++)
			cout << v[i] << ' ';
		cout << endl;
		return;
	}
	
	for(int i = start+1; i < t; i++){
		dfs(i,v);
		v.pop_back();
	}
}

int main(){
	
	
	while(1){

		cin >> t;
		if(t==0) break;
		
		for(int i = 0; i < t; i++) cin >> arr[i];
		for(int i = 0; i < t; i++){
			vector<int> v;
			dfs(i,v);
		}
		cout << endl;
	}
}
