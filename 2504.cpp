#include <cstdio>
#include <cstring>

int main(){
	int st[15]; // -2 = '(' , -3 = '['
	char str[31];
	int top = -1, tmp_ret = 0, ret = 0, tmp = 0;
	
	
	scanf("%s", str);
	
	for(int i = 0; i < strlen(str); i++){
		if(str[i] == '('){
			st[++top] = -2;
		}
		else if(str[i] == '['){
			st[++top] = -3;
		}
		else{
			if(str[i] == ')') tmp = -2;
			else tmp = -3;
			
			
			while(1){
				if(top == -1){
					printf("0\n");
					return 0;
				}
				
				if(st[top] > 0){
					tmp_ret+= st[top];
				}
				else if(st[top] == tmp){
					if(tmp_ret == 0) st[top] = -tmp;
					else{
						st[top] = tmp_ret* (-tmp);
					}
					tmp_ret = 0;
					break;
				}
				else{
					printf("0\n");
					return 0;
				}
				
				--top;
			}
		}
		
		if(top == 0 && st[top] > 0){
			ret+=st[top--];
			
		}
		
	}
	if(top ==-1)
		printf("%d\n", ret);
	else
		printf("0\n");
			
}
