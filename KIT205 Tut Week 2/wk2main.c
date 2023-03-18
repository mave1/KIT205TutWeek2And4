#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "bst.h"

void option_insert(List* self)
{
	int insert_data = 0;

	printf("Enter an int to add: ");
	scanf_s("%d", &insert_data);

	insert_at_front(self, insert_data);
}

void option_delete(List* self)
{
	int delete_data;

	printf("Enter an int to delete: ");
	scanf_s("%d", &delete_data);

	delete_list(self, delete_data);
}

void option_print(List* self)
{
	print_list(self);
}

void reverse(List* self)
{
	List reverse_list = new_list();
	int size = 0;

	ListNodePtr current = self->head;
	ListNodePtr next = NULL;

	while (current != NULL) 
	{
		size++;
		current = current->next;
	}

	current = self->head;

	for (int i = 0; i < size; i++) 
	{
		insert_at_front(&reverse_list, current->data);
		current = current->next;
	}

	print_list(&reverse_list);
}

void merge(List* self, List* other) 
{
	List merge_list = new_list();
	ListNodePtr self_current = self->head;
	ListNodePtr other_current = other->head;
	
	while (self_current != NULL && other_current != NULL) {
		if (self_current->data <= other_current->data) {
			insert_at_front(&merge_list, self_current->data);
			self_current = self_current->next;
		}
		else {
			insert_at_front(&merge_list, other_current->data);
			other_current = other_current->next;
		}
	}

	while (self_current != NULL) {
		insert_at_front(&merge_list, self_current->data);
		self_current = self_current->next;
	}

	while (other_current != NULL) {
		insert_at_front(&merge_list, other_current->data);
		other_current = other_current->next;
	}

	reverse(&merge_list);
}

int list()
{
	List my_list = new_list();
	List other_list = new_list();

	int quit = 0;
	printf("Linked List \n");

	while (!quit) {
		int option;

		printf("Enter an int (1 = insert, 2 = delete, 3 = print, 4 = reverse, 5 = merge, 0 = quit): ");
		scanf_s("%d", &option);

		switch (option) {
		case 0:
			quit = 1;
			break;
		case 1:
			option_insert(&my_list);
			break;
		case 2:
			option_delete(&my_list);
			break;
		case 3:
			option_print(&my_list);
			break;
		case 4:
			reverse(&my_list);
			break;
		case 5:
			insert_at_front(&other_list, 12);
			insert_at_front(&other_list, 9);
			insert_at_front(&other_list, 8);
			insert_at_front(&other_list, 2);

			merge(&my_list, &other_list);
		}
	}

	destroy_list(&my_list);
	destroy_list(&other_list);
	printf("\n");
}


int main(int argc, char* argv[]) 
{
	list();
	bst_test();
	
	return;
}