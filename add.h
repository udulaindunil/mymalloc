//int total =0;
//int add(int a,int b){
//	total= a+b;
//	return total;
//}
#include<stdio.h>
#define memorysize 100
int memory[memorysize];
int i;
int *p;
int top=memorysize-1;
int searchingindex=memorysize-1;
int *p2=memory;

int * write(int n,int m,int x){
	if(!memory[n]){
	
		p=&memory[n];
		for(i=n;i<n+m;i++){
			*p++=x;
			}
		memory[top--]=n;
		memory[top--]=m;
		memory[top--]=2;
	
		return &memory[n];
	}
	else{
		printf("Memory already allowcated\n");
	}
}

void myfree(int n){
	//printf(">..>>>%d<<<<< \n",searchingindex);	
	int v;
	while(memory[searchingindex]){
		//	printf(">%d<<<<< \n",memory[searchingindex]);	

		if(memory[searchingindex]==n){
			v=memory[--searchingindex];
		//	printf(" v = %d\n",v);
			searchingindex--;
			//printf(">>>>%d<<<<< \n",memory[searchingindex]);
			memory[searchingindex]=1;	

			break;
			
		}
		
		searchingindex--;
	}
	
	for(i=n;i<n+v;i++){
		memory[i]=00;
	}
	searchingindex=49;
}











void bulid(){
	for(i=0;i<memorysize;i++){
		memory[i]=00;
		
		}
}

void display(){
	for(i=0;i<memorysize;i++){
		printf("%d\t",memory[i]);
		
		}
}

//void write(int n,int m){
//	p=memory[n];
//}

