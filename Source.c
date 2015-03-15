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
	printf("\n");
}
//add element at front (new head) +next,prev
p_type_list_handle l_add_front(p_type_list_handle Dlist){
	type_list *p;

	p = malloc(sizeof(type_list));
	printf("\ntype int at front: ");
	scanf_s("%d", &p->data);
	p->prev = NULL;
	p->next = Dlist->head;
	Dlist->head = p;
	Dlist->counter++;
	//printf("addfront %u", Dlist->counter);

	if(p->next){
		p->next->prev = p;
	}else(Dlist->tail = p);
	return Dlist;
}
//add element at back (new tail) +next,prev
p_type_list_handle l_add_back(p_type_list_handle Dlist){
	type_list *p;

	p = malloc(sizeof(type_list));
	printf("\ntype int at back: ");
	scanf_s("%d", &p->data);
	p->next = NULL;
	p->prev = Dlist->tail;
	Dlist->tail = p;
	Dlist->counter++;
	
	if(p->prev){
		p->prev->next = p;
	}else(Dlist->head = p);
	return Dlist;
}

int menu(){
	int n;
	printf("---MENU---\n");
	printf("1: dodaj na poczatek\n");
	printf("2: dodaj na koniec\n");
	/*printf("3: dodaj przed wybrana pozycja\n");
	printf("4: dodaj za wybrana pozycja\n");
	printf("5: dodaj za elementem o okreslonej wartosci\n");
	printf("6: usun z poczatku\n");
	printf("7: usun z konca\n");
	//printf("8: usun z wybranej pozycji");*/
	printf("9: drukuj liste\n");
	printf("0: wyjscie\n---------\n");
	printf("wybierz opcje: ");
	scanf_s("%d", &n);
	printf("\n");
	return n;
}

int main(){

	int n;
	p_type_list_handle Dlist = (p_type_list_handle)malloc(sizeof(type_list_handle)); //rzutowanie! malloc zwraca wskaünik na void, a øe p_type_list_handle voidem nie jest...przyda sie rzutowacnie
	memset(Dlist,NULL,sizeof(type_list_handle));
	l_init(Dlist);

	printf("%p\n", &Dlist);
	do{
		n=menu();
		switch(n){
			case 1: Dlist = l_add_front(Dlist);
					break;
			case 2: Dlist = l_add_back(Dlist);
					break;
			/*case 3:	head=add_beforepos(head);
					break;
			case 4:	head=add_afterpos(head);
					break;
			case 5:	head=add_afterVAR(head);
					break;
			case 6: head=delfront(head);
					break;
			case 7: head=delback(head);*/
					break;
			case 9: l_print(Dlist);
					break;
			default: break;
		}
	}while(n!=0);
	system("PAUSE");
	return EXIT_SUCCESS;
}
