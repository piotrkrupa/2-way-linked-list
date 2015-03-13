#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
	int data;
	struct list *next, *prev;
}type_list;

typedef struct list_handle{
	type_list *head, *tail;
	unsigned int counter;
}type_list_handle, *p_type_list_handle;

void l_init(p_type_list_handle Dlist){
	Dlist->head = NULL; 
	Dlist->tail = NULL;
	Dlist->counter = 0;
}

void l_print(p_type_list_handle Dlist){
	int i;
	type_list *p;
	p = Dlist->head;
	printf("\nlist size: %u\n", Dlist->counter);
	while(p){
		for(i=0; i < Dlist->counter; i++){
			printf("%u: %d\n", i+1, p->data);
			p = p->next;
		}
	}
}

void l_add_front(p_type_list_handle Dlist){
	type_list *p;

	p = malloc(sizeof(type_list));
	printf("type int: ");
	scanf_s("%d", &p->data);
	p->prev = NULL;
	p->next = Dlist->head;
	Dlist->head = p;
	Dlist->counter++;
	//printf("addfront %u", Dlist->counter);
	if(p->next){
		p->next->prev = p;
	}else(Dlist->tail = p);
}

int main(){

	p_type_list_handle Dlist = (p_type_list_handle)malloc(sizeof(type_list_handle)); //rzutowanie! malloc zwraca wskaünik na void, a øe p_type_list_handle voidem nie jest...przyda sie rzutowacnie
	memset(Dlist,NULL,sizeof(type_list_handle));
	

	l_init(Dlist);
	l_add_front(Dlist);
	l_add_front(Dlist);
	l_add_front(Dlist);
	l_add_front(Dlist);
	//l_add_front(Dlist);
	l_print(Dlist);

	getchar();
	getchar();
	return EXIT_SUCCESS;
}