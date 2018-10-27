#include<stdio.h>
#include"mymalloc.h"
int main(){
struct Node  
{ 
  int data; 
  struct Node *next; 
}; 

struct Node* head = NULL;
head = (struct Node*)MyMalloc(sizeof(struct Node));  
	
	char* v=(char*)MyMalloc(2000);
	head->data = 1; //assign data in first node 
  	head->next = NULL;
	
	printf("the data %d\n",head->data);
	
	MyFree(head);
	MyFree(v);
	display(v);
	memoryReport();
	
}
