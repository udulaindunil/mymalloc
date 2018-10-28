#include<stdio.h>
#include"mymalloc.h"

int main(){
	//printf("the base address %p\n",memory);
	char*p=(char*)MyMalloc(100);
	char*p2=(char*)MyMalloc(14);
	char*p8=(char*)MyMalloc(30000);
	char*p9=(char*)MyMalloc(-13);
	char*p3=(char*)MyMalloc(100);
	MyFree(p2);
	char*p4=(char*)MyMalloc(13);
	MyFree(p4);
	
	
	//char*p5=(char*)mymalloc(1);
	
	MemoryReport();
}

