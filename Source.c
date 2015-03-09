#include <stdio.h>
#include <stdlib.h>

typedef struct dlist{
	int data;
	struct dlist *next, *prev;
}type_dlist;

typedef struct dlistVar{
	type_dlist *head, *tail;
	unsigned count;
}type_dlistVar;

void l_init(type_dlistVar *List){
	List->head  = List->tail  = NULL;
	List->count = 0;
}

int main(){

	type_dlistVar *List;
	printf("asd");
	getchar();
	return EXIT_SUCCESS;
}