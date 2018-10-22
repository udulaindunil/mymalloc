#include<stdio.h>
#define memorysize 200
char memory[memorysize];
int i=1;
char *p;
int top=memorysize-1;
int searchingindex=memorysize-1;
char *p2=memory;
int space;
int j;

int setvalue(int size){
	
	while(!(memory[i]==NULL)){
		
		i++;
		
	}
	j=i;
	while(memory[j]==NULL){
		j++;
	}
	space=j-i;
	if(space>size){
		return i;
	}
	else{
		//printf("j == %d %c  \n",j,(char)memory[j+5]);
		if(memory[j]){
			i=j;
			return setvalue(size);
		}
		else{
			return j;
		}
		
	}
	
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
		int n=setvalue(m);
			//printf("The space valiu is %d \n",space);
			
		int h;
		h=tosearch(n,m);
	//	printf(">>>>%d\n",h);
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
		memory[i]=NULL;//(char)45;
	}
	searchingindex=memorysize-1;
}


void bulid(){
	for(i=0;i<memorysize;i++){
		memory[i]=(char)79;
		
		}
}

void display(){
	//int p = setvalue();
	int j=1;
	for(i=0;i<memorysize;i++){
		if(i<150){
		printf("%c\t",memory[i]);	
		}
		else{
		//printf("\n");
		while(memory[memorysize-j]){
			printf("%d \t",(int)memory[memorysize-j]);
			j++;
		}
		}		
		}
}

