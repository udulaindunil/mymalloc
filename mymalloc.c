#include<stdio.h>
//#include"mymalloc.h"
#define memorysize 25000
char memory[memorysize]={'\0'};

int metasize=sizeof(char)+sizeof(int);

void defrag(){
	char *nextslot;
	char temp;
	int si;
	nextslot=memory;
	while(*nextslot){
	
	if(*(nextslot)=='f'){
		temp=*(nextslot+(int)*(nextslot+1)+metasize);
			if(temp=='f'){
				*(int*)(nextslot+1)=*(int*)(nextslot+1)+*(int*)(nextslot+*(int*)(nextslot+1)+metasize+1);
				*(int*)(nextslot+*(int*)(nextslot+1)+metasize+1)='\0';
			 	*(char*)(nextslot+*(int*)(nextslot+1)+metasize)='\0';
			}
			 
	}
	si=*(int*)(nextslot+1);
	nextslot=nextslot+si+metasize;
	
	}	
}

void myfree(char* x){
	//char *nextslot;	
	*(x-(sizeof(int)+sizeof(char)))='f';
	//nextslot = x+*(int*)(x-sizeof(int));
	//printf("next status %c\n",*nextslot);
	//printf("next slote size%d\n",*(nextslot+1));
//	printf("freee %d\n",*(int*)(x-sizeof(int)));
//		if(*nextslot=='f'){
//			*(int*)(x-sizeof(int))=*(x-sizeof(int))+*(nextslot+1);
//			 *(nextslot+1)='\0';
//			 *nextslot='\0';
//	}
	defrag();
}


void initialize(){
	*memory='f';
	*(int*)(memory+sizeof(char))=(memorysize-1)-metasize;
	
}

char * allocate(int size){
	char * ptr2=memory;
	int st_size = 0;
	if(size<24999){
			while(size<24999){ 
				st_size = *(int*)(ptr2+1);

				if((st_size>=size)&&(*ptr2=='f')){
					
					//rebuilding
					if(st_size==size){
						return (ptr2);	
					}
					else{
						*(ptr2+metasize+size)='f';
						*(int*)(ptr2+metasize+size+1)=st_size-size;
						return (ptr2);
					}
					
				}
				else if(ptr2+st_size+size+metasize >=memory+(memorysize-1)){
						printf("Sorry! No Enough Memory...\n");
						return NULL;	
				}
				else{

					ptr2 = ptr2+metasize+st_size;			
				}
		}
		return ptr2;
	}
	else{
		printf("Sorry! No Enough Memory...\n");
		return NULL;
	}
}



void *mymalloc(int size){
	char *ptr,*remain;
	if(size>=0){   //check the valid allocation 
		if(!*memory){
			initialize();	
			}    
			
		ptr=allocate(size); //this gives suatable pinter to allocate
		*ptr='a';
		*(int*)(ptr+1)=size;
		printf("the return address %p \n",ptr+metasize);
	return (void*)ptr+metasize;
	}else{
		printf("Invalid memory size .Can't Allocate'\n");
		return NULL;
	}
}

int main(){
	printf("the base address %p\n",memory);
	char *p = (char*)mymalloc(1);
	char *p1 = (char*)mymalloc(10);
	char *p3 = (char*)mymalloc(20);
	myfree(p1);
	char *p4 = (char*)mymalloc(1);
	char *p5 = (char*)mymalloc(1);
	//myfree(p5);

}


