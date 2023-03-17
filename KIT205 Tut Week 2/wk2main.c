#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) 
	{
		int rdata = current->data;
		insert_at_rear(&reverse_list, rdata);

		prev = current;
		current = current->next;
	}

	print_list(&reverse_list);

}

void merge(List* self, List* other) 
{

}


int main(int argc, char* argv[])
{
	List my_list = new_list();

	int quit = 0;

	while (!quit) {
		int option;

		printf("Enter an int: ");
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
		}

	}


	destroy_list(&my_list);
}

	/*int data;

	printf("Enter an int ");
	scanf_s("%d", &data);

	while (!(data == 0)) {
		insert_at_front(&test, data);
		print_list(&test);

		printf("Enter an int ");
		scanf_s("%d", &data);
		destroy_list(&test);
	}*/


	//insert_at_front(&test, 6);
	//insert_at_front(&test, 5);
	//insert_at_front(&test, 2);
	//insert_at_front(&test, 1);

	//print_list(&test);

	//insert_in_order(&test, 3);
	//print_list(&test);

	//delete_list(&test, 5);
	//print_list(&test);

	//destroy_list(&test);
	//print_list(&test);
