#include <stdio.h>

int main(){
	int s1,s2,n;
	char arr[3] = {'1','0','0'};
	char tmp;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d %d", &s1, &s2);
		s1 -=1; s2-=1;
		tmp = arr[s1];
		arr[s1] = arr[s2];
		arr[s2] = tmp;
	}
	
	for(int i = 0; i < 3; i++){
		if(arr[i] == '1'){
			printf("%d",i+1);
			break;
		}

	}
}
