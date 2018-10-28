#include<stdio.h>
#define memorysize 25000
char memory[memorysize]={'\0'};

int metasize=sizeof(char)+sizeof(int);

void go(){
	char*p;
	p=memory;
	while(*p){
		printf(" status %c \n",*p);
		printf(" the size %d \n",*(int*)(p+1));
		p=p+metasize+*(int*)(p+1);
	}
	
}

void reshedule(){
	char *nextslot;
	char temp;
	int si;
	nextslot=memory;
	
	while(*nextslot){
		
	if((*nextslot=='f')&&(*(char*)(nextslot+*(int*)(nextslot+1)+metasize)=='f')){
		*(int*)(nextslot+1)=*(int*)(nextslot+1)+metasize+*(int*)(nextslot+*(int*)(nextslot+1)+metasize+1);
		
		nextslot=memory;
	}
	si=*(int*)(nextslot+1);
	nextslot=nextslot+si+metasize;
	}	
}

void myfree(char* x){
	*(x-(sizeof(int)+sizeof(char)))='f';
	reshedule();
}


void initialize(){
	*memory='f';
	*(int*)(memory+sizeof(char))=(memorysize-1)-metasize;
}

char * allocate(int size){
	char * ptr2=memory;
	int st_size = 0;
	if(size<memorysize-1){
			while(size<memorysize-1){ 
				st_size = *(int*)(ptr2+1);

				if((st_size>=size)&&(*ptr2=='f')){
					
					if((st_size>=size+(metasize+1))&&(*ptr2=='f')){
						*ptr2='a';
						*(int*)(ptr2+1)=size;
						
						//display(ptr);
						*(ptr2+metasize+size)='f';
						*(int*)(ptr2+metasize+size+1)=st_size-(size+metasize);
						return (ptr2);
					}else{
						*ptr2='a';
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

void display(char *p){
	char* status="Allocated";
	printf("Allocated Address\t\t Status\t\t Allocated Size(bytes) \t\t Return Address\n");
	printf("%p \t\t %c--%s \t\t %d \t\t\t %p\n\n",p,*p,status,*(int*)(p+1),p+metasize);
}

void *mymalloc(int size){
	char *ptr;
	if(size>=0){   //check the valid allocation 
		if(!*memory){
			*memory='f';
			*(int*)(memory+sizeof(char))=(memorysize-1)-metasize;	
			}    
		ptr=allocate(size); //this gives suatable pinter to allocate
	return (void*)ptr+metasize;
	}else{
		printf("Invalid memory size .Can't Allocate'\n");
		return NULL;
	}
}

void memoryReport(){
	char* base=memory;
	char* fr="Free     ";
	char* al="Allocated";
	printf("Return Addresses\t Status \t Allocated size(bytes)\n");
	while(*base){
		printf("%p\t %s\t\t %d\n",base+metasize,(*base=='a')? al : fr,*(int*)(base+1));
		base=base+metasize+*(int*)(base+1);
	}
}


int main(){
	printf("the base address %p\n",memory);
	char*p=(char*)mymalloc(100);
	char*p2=(char*)mymalloc(14);
	
	char*p3=(char*)mymalloc(100);
	myfree(p2);
	char*p4=(char*)mymalloc(13);
	//char*p5=(char*)mymalloc(1);
	
	memoryReport();
}


