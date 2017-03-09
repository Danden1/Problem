#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	int data;
	Node *next;	
};

struct Stack{
	Node *top;
	int num_of_data	;
};

void Push(Stack *st, int data);
void Pop(Stack *st);

int main(){
	int n,m;
	char arr[15];
	Stack st;
	
	st.top = NULL;
	st.num_of_data = 0;
	scanf("%d", &n);
	while(getchar() != '\n');
	
	for(int i = 0; i < n; i++){
		gets(arr);

		if(!strncmp(arr,"size",4)){
			printf("%d\n", st.num_of_data);
		}
		else if(!strncmp(arr, "pop", 3)){
			Pop(&st);
		}
		else if(!strncmp(arr,"empty", 5)){
			if(st.num_of_data == 0)
				printf("%d\n", 1);
			else
				printf("%d\n", 0);
		}
		else if(!strncmp(arr, "top", 3)){
			if(st.num_of_data == 0){
				printf("%d\n", -1);	
				continue;
			}
			printf("%d\n", st.top->data);	
		}
		else{
			
				m = atoi(&arr[5]); Push(&st,m);
		}
	}	
}
void Push(Stack *st, int data){
	Node *newnode;
	newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data; newnode->next = st->top;
	st->top = newnode;
	st->num_of_data +=1;

}

void Pop(Stack *st){
	if(st->num_of_data == 0){
		printf("-1\n");
		return;	
	}
	Node *tmp;
	tmp = st->top;
	printf("%d\n", tmp->data);
	st->top = st->top->next;
	free(tmp);
	st->num_of_data -= 1;
}
