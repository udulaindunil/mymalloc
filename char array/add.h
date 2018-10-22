#include<stdio.h>
#define memorysize 200
char memory[memorysize];
int i;
char *p;
int top=memorysize-1;
int searchingindex=memorysize-1;
char *p2=memory;
int space;

int setvalue(){
	i=1;
	int temp1=0;
	while(!memory[i]==NULL){
		
		i++;
		
	}
	temp1=i;
	return temp1;
}





int tosearch(int n,int freesize){
	
	if(memory[n]){
		//printf("Allocated\n");
	}
	else{
	
	for(i=memorysize-2;i>150;i=i-3){
		if((freesize<memory[i])&&(memory[i-1]==1)){  
			//printf("%d\n",memory[i+1]);
			memory[i]=freesize;
			memory[i-1]=2;
			
			return memory[i+1];	
			}
		
		else if(memory[i]==0){
			memory[top--]=n;
			memory[top--]=freesize;
			memory[top--]=2;
			
			break;			
		}		
	}
	}
	return n;
}

char * write(int m,char x){
		int asci=(int)x;
		int n=setvalue();
			//printf("The space valiu is %d \n",space);
			
		int h;
		h=tosearch(n,m);
		printf(">>>>%d\n",h);
		if(memory[h]==79){
			printf("Memory allocated\n");
		}
		else{
			p=&memory[h];
			for(i=h;i<h+m;i++){
				memory[i]=asci;
			}

		return &memory[h];
	
		}			
		}

void myfree(int n){
		
	int v;
	while(memory[searchingindex]){
		if(memory[searchingindex]==n){
			v=memory[--searchingindex];
			searchingindex--;
			memory[searchingindex]=1;	
			break;
			}
		searchingindex--;
	}
	
	for(i=n;i<n+v;i++){
		memory[i]=(char)79;
	}
	searchingindex=memorysize-1;
}


void bulid(){
	for(i=0;i<memorysize;i++){
		memory[i]=(char)79;
		
		}
}

void display(){
	int p = setvalue();
	for(i=0;i<p;i++){
		printf("%c\t",memory[i]);
		
		}
}

