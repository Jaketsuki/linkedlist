#include "linkedlist.h"

int add_to_list(linked_list *ll, char *s){
struct linked_list *ptr;
int i = 1;
ptr = ll;
while(ptr->next != NULL){
	i++;
	ptr = ptr->next;
}
ptr->next=(linked_list *)malloc(sizeof(linked_list));
ptr->next->data = s;
ptr->next->index = i;
ptr->next->previous=ptr;
ptr->next->next = NULL;
return ptr->next->index;
}

int display_item(linked_list *ll){
if(ll->data == NULL)return -1;
else
	printf("%s",ll->data);
return 0;
}

int display_list(linked_list *ll){
struct linked_list* ptr;
int i = 0;
ptr = ll;

while(ptr->next != NULL){
	ptr = ptr->next;
	i++;
	printf("\nindex:%d data:%s\n",i,ptr->data);
}
return i;
}

linked_list * search_from_list(linked_list *ll, char *s){
do
{
		if(ll->data == s)return ll;
	ll = ll->next;
} while(ll != NULL);
return NULL;
}

int delete_from_list(linked_list *ll, int index){
struct linked_list* ptr;
struct linked_list* ptr_next;
int i = 0;
ptr = ll;
if(index == 0)return -1;
while(ptr != NULL){
	if(ptr->index == index){
		ptr_next->next = ptr->next;
		free(ptr);
		ptr_next=ll->next;
			while(ptr_next != NULL){
			i++;
			ptr_next = ptr_next->next;
			}
		return i;
	}
	ptr_next = ptr;
	ptr = ptr->next;
}

return -1;
}

int empty_list(linked_list *ll){
if((ll->next == 0) || (ll == 0)) return -1;
free(ll->next);
ll->next = NULL;
if(ll->next == 0)return 0;
else
	return -1;
}

linked_list * swap_items(linked_list *f, linked_list *s){
struct linked_list* ptr;
/*if list are */
if((f->next == s) && (s != 0)){
	f->next = s->next;
	s->next = f;
	f->previous->next = s;

	s->previous = f->previous;
	f->previous = s;
	if(f->next != 0){
		f->next->previous = f;
		return 0;
	}
	else
		return 0;
}
if((s->next == f) && (f != 0)){
	s->next = f->next;
	f->next = s;
	s->previous->next = f;

	f->previous = s->previous;
	s->previous = f;
	if(s->next != 0){
		s->next->previous = s;
		return 0;
	}
	else
		return 0;
}



/*if f or s is next to 0*/
if((f->next == 0) || (s->next == 0)){
	ptr = f->next;
	f->previous->next = s;
	s->previous->next = f;

	f->next = s->next;
	s->next = ptr;

	ptr = s->previous;

	s->previous = f->previous;
	f->previous = ptr;

		if(f->next != 0){
			f->next->previous = f;
		return 0;
		}
		else
		s->next->previous = s;
		return 0;
	}
	
/* everything else*/
if((s != 0)&&(f != 0)){
	ptr = f->next;
	
	f->previous->next = s;
	s->previous->next = f;
	
	f->next = s->next;
	s->next = ptr;
	
	ptr = s->previous;
	s->previous = f->previous;
	f->previous = ptr;
	
	f->next->previous = f;
	s->next->previous = s;
return 0;
}
exit(0);

}



int sort_list(linked_list *ll){
struct linked_list* ptr;
struct linked_list* ptr_previous;
struct linked_list* ptr_root;
int i, number, j, k;
k = linked_list_size(ll);
ptr = ll->next;
ptr_previous = ll->next;
for(j = 0; j < k; j++){

	for(i=0; i<k; i++){
	
		if((ptr != 0) && (ptr->data < ptr_previous->data)){
		ptr_root = ptr;

		swap_items(ptr_previous , ptr_root);
		ptr = ptr_previous;
		ptr_previous = ptr_root;
		}
	if(ptr != 0)ptr = ptr->next;

	}
ptr_previous = ptr_previous->next;
ptr = ptr_previous;
}

return 1;
}

int linked_list_size(linked_list *ll){
struct linked_list* ptr;
int i=0;
ptr=ll->next;
	while(ptr != 0){
	i++;
	ptr=ptr->next;
	}
return i;
}
int linkedlist_status(linked_list *ll){
	struct linked_list* ptr;
int i=0;
ptr=ll->next;
	while(ptr != 0){
	i++;
	ptr=ptr->next;
	}
return i;
	
}
