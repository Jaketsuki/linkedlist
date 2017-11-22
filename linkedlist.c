#include "linkedlist.h"

int add_to_list(linked_list *ll, char *s){
linked_list *ptr;
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
printf("\nindex:%d data:%s\n",ll->index,ll->data);
return 0;
}

int display_list(linked_list *ll){
linked_list* ptr;
int i = 0;
ptr = ll;

while(ptr->next != NULL){
	printf("\nindex:%d data:%s\n",ptr->index,ptr->data);
	ptr = ptr->next;
	i++;
}
return i;
}

int delete_from_list(linked_list *ll, int index){
linked_list* ptr;
linked_list* ptr_next;
int i;
ptr_next = ll;
if(index == 0)return -1;
while(ll != NULL){
	if(ll->index == index){
		ptr->next = ll->next;
		ptr = ll;
		free(ll);
		return linkedlist_status(ptr_next);
	}
ptr = ll;
ll = ll->next;
}

return -1;
}

int empty_list(linked_list *ll){
linked_list *ptr;
ptr = ll->next;
while(linkedlist_status(ll) != 1){
	ptr = ptr->next;
		if(ptr->next == 0){
			delete_from_list(ll,ptr->index);
			ptr = ll->next;
		}
}
return 1;
}


int linkedlist_status(linked_list *ll){
int i=0;
	while(ll->next != 0){
	i++;
	ll=ll->next;
	}
return i;
}
