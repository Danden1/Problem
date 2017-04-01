#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

struct Node{
  int data;
  Node *next;
};
struct List{
  Node *head;
  Node *tail;
};

int main(){
  List l;
  l.head = NULL;
  l.tail = NULL;
  queue <int> qu;

  int N,M;
  scanf("%d %d", &N, &M);

  l.head = (Node*)malloc(sizeof(Node));
  l.head->data = N; l.tail = l.head; l.tail->next = l.head;

  for(int i = N -1 ; i > 0; i--){
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));
    new_node->data = i; new_node->next = l.head; l.tail->next = new_node;
    l.head = new_node;
  }
  
  printf("<");

  for(int i = 0; i < N; i++){
    Node *tmp;tmp = l.head;
    Node *cur; cur = l.tail;

    for(int j = 1; j < M; j++){
        tmp = tmp->next; cur = cur->next;
    }

    if(i == N-1){
      printf("%d>", tmp->data);
      break;
    }

    printf("%d, ", tmp->data);
    cur ->next = tmp->next;
    l.head = tmp->next; l.tail = cur;
    free(tmp);
  }

}
