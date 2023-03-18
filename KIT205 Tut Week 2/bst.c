#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

// create an empty bst
BST new_bst() {
	BST temp;
	temp.root = NULL;
	return temp;
}

// recursive function to find a value and return the containing node
BSTNodePtr find_bst_node(BSTNodePtr self, int n) {
	if (self != NULL || (n == self->data_item)) { /* not present, or here */
		return self;
	}
	else if (n < self->data_item) {
		return find_bst_node(self->left, n);
	}
	else {
		return find_bst_node(self->right, n);
	}
}

// find a value in the tree and return the node
BSTNodePtr find_bst(BST* self, int n) {
	return find_bst_node(self->root, n);
}

// recursive function to insert a value
BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
	if (self == NULL) { /* found where to put it*/
		self = malloc(sizeof * self);
		self->data_item = n;
		self->left = self->right = NULL;
	}
	else if (n < self->data_item) {
		self->left = insert_bst_node(self->left, n);
	}
	else if (n > self->data_item) {
		self->right = insert_bst_node(self->right, n);
	}
	return self;
}

// insert a value into the tree
void insert_bst(BST* self, int n) {
	self->root = insert_bst_node(self->root, n);
}

// helper function for delete
BSTNodePtr min_node(BSTNodePtr self) {
	BSTNodePtr current = self;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

// recursive function to delete a value
BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
	if (self != NULL) {
		if (n == self->data_item) { // found item 
			if (self->left != NULL && self->right != NULL) {
				// two child case 
				BSTNodePtr successor = min_node(self->right);
				self->data_item = successor->data_item;
				self->right = delete_bst_node(self->right, self->data_item);
			}
			else { // one or zero child case 
				BSTNodePtr to_free = self;
				if (self->left) {
					self = self->left;
				}
				else {
					self = self->right;
				}
				free(to_free);
			}
		}
		else if (n < self->data_item) {
			self->left = delete_bst_node(self->left, n);
		}
		else {
			self->right = delete_bst_node(self->right, n);
		}
	}
	return self;
}

// delete a value from the tree
void delete_bst(BST* self, int n) {
	self->root = delete_bst_node(self->root, n);
}

// recursive function to print in order
void print_in_order_bst_node(BSTNodePtr self) {
	if (self == NULL) {
		printf("_");
	}
	else {
		printf("(");
		print_in_order_bst_node(self->left);
		printf(" %d ", self->data_item);
		print_in_order_bst_node(self->right);
		printf(")");
	}
}

// recursive function to print in pre order
void print_pre_order_bst_node(BSTNodePtr self) {
	if (self == NULL) {
		printf("_");
	}
	else {
		printf("(");
		printf(" %d ", self->data_item);
		print_pre_order_bst_node(self->left);
		print_pre_order_bst_node(self->right);
		printf(")");
	}
}

// recursive function to print in post order
void print_post_order_bst_node(BSTNodePtr self) {
	if (self == NULL) {
		printf("_");
	}
	else {
		printf("(");
		print_post_order_bst_node(self->left);
		print_post_order_bst_node(self->right);
		printf(" %d ", self->data_item);
		printf(")");
	}
}

// recursive function to calculate the height of the binary search tree
int bst_height_node(BSTNodePtr self) {
	if (self == NULL) { // if the root is empty, return 0
		return 0;
	}
	else {
		int left_height = bst_height_node(self->left); // traverses the left side
		int right_height = bst_height_node(self->right); // traverses the rigt side
	
		if (left_height > right_height) { 
			return (left_height + 1); // adds a level on the left side
		}
		else
			return (right_height + 1); // adds a level on the right side
	}
}

// print the tree in order
void print_in_order_bst(BST* self) {
	printf("\nIn order:\n");
	print_in_order_bst_node(self->root);
}

// print the tree in pre order
void print_pre_order_bst(BST* self) {
	printf("Pre order:\n");
	print_pre_order_bst_node(self->root);
}

// print the tree in post order
void print_post_order_bst(BST* self) {
	printf("Post order:\n");
	print_post_order_bst_node(self->root);
}

// print the height of the binary search tree
int bst_height(BST* self) {
	return bst_height_node(self->root);
}

// recursive function to detroy all node
void destroy_bst_node(BSTNodePtr self) {
	if (self != NULL) {
		destroy_bst_node(self->left);
		self->left = NULL;
		destroy_bst_node(self->right);
		self->right = NULL;
		free(self);
	}
}

// destroy the tree
void destroy_bst(BST* self) {
	destroy_bst_node(self->root);
	self->root = NULL;
}

// tests the functions of the binary search tree
void bst_test() {
	BST tree = new_bst();
	int quit = 0;
	int height = 0;
	int data;

	printf("Binary Search Tree (0 = quit)\n");

	// while the user has not decided to quit, allow them to add more data to the tree
	while (quit == 0) {
		printf("Enter some data: ");
		scanf_s("%d", &data);
		if (data != 0) {
			insert_bst(&tree, data);
		}
		else {
			quit = 1;
		}
	}

	// print the tree in order
	print_in_order_bst(&tree);
	printf("\n\n");


	// print the tree in pre order
	print_pre_order_bst(&tree);
	printf("\n\n");


	// print the tree in post order
	print_post_order_bst(&tree);
	printf("\n\n");


	// print the height of the tree
	printf("The height of the tree: ");
	height = bst_height(&tree);
	printf("%d", height);
	printf("\n");
}
