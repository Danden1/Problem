#include <stdio.h>
#include <string>
#include <algorithsm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector <pair<int, string> > v (20000);
  int N;
  string tmp;

  scanf("%d", &N);
  for(int i = 0; i < N; i++){
      cin >> v[i].second;
      v[i].first = v[i].second.length();
  }
  sort(v.begin(), v.begin() + N);

  for(int i = 0; i < N; i++){
      if(tmp != v[i].second)
        cout << v[i].second << '\n';
      tmp = v[i].second;
  }

}
