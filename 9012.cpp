#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

int main(){
  int N, len,chk;
  stack <char> st;
  char arr[50];
  scanf("%d", &N);

  for(int i = 0; i < N; i++){
      scanf(" %s", arr);
      len = strlen(arr);
      chk = true;

      for(int j = 0; j < len; j++){
        if(arr[j] == '('){
          st.push('(');
        }
        else if(!st.empty())
          st.pop();

        else{
          chk =false;
          break;
        }
      }
      if(chk && st.empty())
        printf("YES\n");
      else
        printf("NO\n");
      while(!st.empty()) st.pop();
  }
}
