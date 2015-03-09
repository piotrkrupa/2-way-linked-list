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

void l_print(type_dlistVar *List){
	type_dlist *p;
	p = List->head;
	while(p){
		printf("asd %d: %d", List->count, p->data);
		p = p->next;
	}
}

void l_add_front(type_dlistVar *List){
	type_dlist *p;
	p = malloc(sizeof(type_dlist));
	printf("type int:");
	scanf_s("%d", p->data);
	p->prev = NULL;
	p->next = List->head;
	List->tail = p;
	List->count++;

}

int main(){

	type_dlistVar *List;

	printf("asd");
	getchar();
	return EXIT_SUCCESS;
}