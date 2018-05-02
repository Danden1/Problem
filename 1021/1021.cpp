#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
	int N, M, pos, count = 0;
	
	cin >> N >> M;
	
	deque<int> de(N);
	
	for(int i = 1; i <=N; i++){
		de[i-1] = i;
	}
	
	deque<int> de_copy {de};
	
	for(int i = 0; i < M; i++){
		cin >> pos;
		int dis1, dis2 = 0;
		
		auto iter = find(de.begin(), de.end(), pos);
		
		dis1 = iter - de.begin();
		dis2 = de.begin() + N - iter ;
		dis1 = dis1 <= dis2 ? dis1 : dis2;
		
		count += dis1;
		
		copy(iter ,de.end(), de_copy.begin());
		if(dis1!=0)
			copy(de.begin(), iter, de_copy.begin()+(de.begin()+N-iter));
			
		de = de_copy;
		de.resize(N);
		de_copy.resize(N);
		
		de.pop_front();
		
		de_copy = de;
		
		N-=1;
		
	}
	
	cout << count <<endl;
	
	return 0;
}
