#include <stdio.h>

int main(){
	int h,w,n,T,re;
	
	scanf("%d", &T);
	
	for(int i = 0; i < T; i++){
		scanf("%d %d %d",&h,&w,&n);
		if(n<h)
			printf("%d\n",  n*100+n/h+1);
		else if(n%h == 0 || h%n == 0 )
			printf("%d\n", h*100 + n/h);
		else
			printf("%d\n", n%h*100+n/h+1);
				
	}
		
}
