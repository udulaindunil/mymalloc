#include<stdio.h>
#include<unistd.h>
#include"mymalloc.h"
int main(){
struct Node  
{ 
  int data; 
  struct Node *next; 
}; 

struct Node* head = NULL;

	head = (struct Node*)MyMalloc(sizeof(struct Node));  
	char* v=(char*)MyMalloc(1000);
	head->data = 1; //assign data in first node 
  	head->next = NULL;
  	display(v);
	MyFree(head);
	//MyFree(v);	
	char*p=(char*)MyMalloc(100);
	char*p2=(char*)MyMalloc(14);
	char*p3=(char*)MyMalloc(100);
	MyFree(p2);
	char*p4=(char*)MyMalloc(8);
	char*p5=(char*)MyMalloc(1);
	memoryReport();
	
}
