#include<stdio.h>
#define memorysize 200
int memory[memorysize];
int i;
int *p;
int top=memorysize-1;
int searchingindex=memorysize-1;
int *p2=memory;
int space;

int setvalue(){
	i=1;
	int temp1=0;
	while(!memory[i]==0){
		
		i++;
		
	}
	temp1=i;
	while(memory[i]==0){
		i++;
	}
	printf("i value  %d\n",i);

	space=i-temp1;

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

int * write(int m,int x){
		int n=setvalue();
			//printf("The space valiu is %d \n",space);
		if(space>m){
			printf("Here should run\n");
		}		
		int h;
		h=tosearch(n,m);
		if(memory[h]){
			printf("Memory allocated\n");
		}
		else{
			p=&memory[h];
			for(i=n;i<n+m;i++){
			*p++=x;
			}

		return &memory[n];
	
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
		memory[i]=0;
	}
	searchingindex=memorysize-1;
}


void bulid(){
	for(i=0;i<memorysize;i++){
		memory[i]=0;
		
		}
}

void display(){
	for(i=0;i<memorysize;i++){
		printf("%d\t",memory[i]);
		
		}
}

