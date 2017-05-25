#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

string s;

int main(){
  int chk = 1,n,m,pop_num,pu_num = 1, top = -1;
  int *st;
  scanf("%d", &n);
  st = (int*)malloc(sizeof(int)*n);

  for(int i = 0; i < n; i++){
    scanf("%d", &m);

    if(chk < m+1){
      for(;pu_num <= m; pu_num++){
        chk +=1;
        st[++top]= pu_num;
        s += '+';
      }
    }
      pop_num = st[top--];
      s +='-';
      if(!(pop_num == m)){
        printf("NO\n");
        return 0;
      }
  }
  for(int i = 0; i < s.length(); i++){
    printf("%c\n", s[i]);
  }

}
