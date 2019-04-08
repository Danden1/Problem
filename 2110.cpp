#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, c;
	int arr[200000];
	
	cin >> n >> c;
	for(int i = 0; i < n; i++) scanf("%d", arr+i);
	sort(arr,arr+n);
	
	int left = 0, right = arr[n-1]-arr[0]+1;

	while(left + 1 < right){
		int mid = (left+right)/2;
		int cnt = 1;
		int start = arr[0];
		
		for(int i = 1; i < n; i++){
			if(arr[i] - start >= mid){
				cnt++;
				start =arr[i];
			}
		}
		
		if(cnt < c) right = mid;
		else		 left = mid;
		
	}
	
	cout << left;
	
}
