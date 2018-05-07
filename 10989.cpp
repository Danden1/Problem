//counting sort

#include <stdio.h>

int main(){
	
	short arr[10000] = {0};
	int n, num;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n; i++){
		scanf("%d", &num);
		arr[num-1] +=1;
	}
	
	for(int i = 0; i < 10000; i++){
		while(arr[i]-- != 0){
			printf("%d\n", i+1);
			
		}
	}
	
	return 0;
}
