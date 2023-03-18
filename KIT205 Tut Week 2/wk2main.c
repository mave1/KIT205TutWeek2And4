#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "bst.h"

// a function to insert a number into the front of the list
void option_insert(List* self) {
	int insert_data = 0;

	printf("Enter an int to add: ");
	scanf_s("%d", &insert_data);

	insert_at_front(self, insert_data);
}

// a function to delete an item from the list
void option_delete(List* self) {
	int delete_data;

	printf("Enter an int to delete: ");
	scanf_s("%d", &delete_data);

	delete_list(self, delete_data);
}

// a function to display the list
void option_print(List* self) { 
	print_list(self);
}

// a function that reverses a linked list
List reverse(List* self) {
	List reverse_list = new_list(); // creating a new list for the reverse
	int size = 0;

	ListNodePtr current = self->head;
	ListNodePtr next = NULL;

	// counts the size of the list
	while (current != NULL) {
		size++;
		current = current->next;
	}

	// reset the pointer
	current = self->head;

	// insert at the front until at the end of the list
	for (int i = 0; i < size; i++) {
		insert_at_front(&reverse_list, current->data);
		current = current->next;
	}

	// display list
	return reverse_list;
}

// a function to merge two ordered linked lists
List merge(List* self, List* other) {
	List merge_list = new_list(); //create a list that the two lists will be merged into
	ListNodePtr self_current = self->head;
	ListNodePtr other_current = other->head;
	
	// while not at the end of each list, insert the smaller number into the merged list
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

	// reverse and return the merged list so the smaller numbers are at the front
	merge_list = reverse(&merge_list);
	return merge_list;
	
}

// function to display the options of the program
int list() {
	List my_list = new_list();
	List other_list = new_list();

	int quit = 0;
	printf("Linked List \n");

	// while not quit, display the menu
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
			my_list = reverse(&my_list);
			break;
		case 5:
			// hardcode a second list to merge with the user's inputted list
			insert_at_front(&other_list, 12);
			insert_at_front(&other_list, 9);
			insert_at_front(&other_list, 8);
			insert_at_front(&other_list, 2);

			my_list = merge(&my_list, &other_list);
			break;
		}
	}

	// destroy both lists
	destroy_list(&my_list);
	destroy_list(&other_list);
	printf("\n");
}

// tests the linked list and binary search tree code
int main(int argc, char* argv[]) {
	list();
	bst_test();
	
	return;
}