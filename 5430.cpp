/*
이번 코드는 입력 관련해서 좀 곤란했습니다. 나머지 구현은 쉬웠습니다.

R뒤집기는 r_chk로 체크해서 뒤집혀 있으면, 뒤에서 아니면 앞에서 원소를 뽑았습니다.
*/

#include <iostream>
#include <deque>
#include <string>
using namespace std;


int main(){
	int T,n;
	string p;
	bool r_chk = false, err = false;
	
	cin >> T;
	
	for(int i = 0; i < T; i++){
		cin >> p;
		cin >> n;
		cin.ignore();
		
		deque<int> de(n);
		
		for(int j =0; j < n; j ++){
			getchar();
			cin >> de[j];
		}
		getchar();
		
		cin.ignore();
		
		
		for(int j =0; j < p.size();j++){
			if(p[j] == 'R')
				r_chk = (r_chk == false ? true : false);	

			else{
				if(de.empty()){
					err= true;
					cout << "error\n";
					break;
				}
				else{
					if(r_chk)
						de.pop_back();
					else
						de.pop_front();
				}
			}
		}
		
		if(!err){
			cout << "[";
			if(!r_chk){
				for(int j = 0; j < de.size(); j++)
					j == de.size()-1 ? cout <<de[j]<<"]" << endl : cout << de[j]<<","; 
			}
			else{
				for(int j = 0; j < de.size(); j++)
					j == de.size()-1 ? cout <<de[de.size()-1-j]<<"]" << endl : cout << de[de.size()-1-j]<<","; 
			}
			if(de.size() == 0)
				cout << "]" <<endl;
		}
		
		err = false;
		r_chk = false;
	}
	
	return 0;
	
}
