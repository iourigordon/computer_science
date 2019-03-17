#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "print_tree.h"

struct rb_node {
  	rb_node *left,*right;
  	int element;
	struct rb_node* parent;
	int color;
};

typedef struct rb_node rb_tree;

#define LEAF NULL
#define RED 1
#define BLACK 0
#define TREE_DATA_SIZE 15

static int tree_data[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

void insert_repair_tree(struct rb_node* n);
void insert_recurse(struct rb_node* root, struct rb_node* n);

struct rb_node* parent(struct rb_node* n) {
	return n->parent; // NULL for root node
}

struct rb_node* grandparent(struct rb_node* n) {
	struct rb_node* p = parent(n);
	if (p == NULL)
		return NULL; // No parent means no grandparent
	return parent(p); // NULL if parent is root
}

struct rb_node* sibling(struct rb_node* n) {
	struct rb_node* p = parent(n);
	if (p == NULL)
		return NULL; // No parent means no sibling
	if (n == p->left)
		return p->right;
	else
		return p->left;
}

struct rb_node* uncle(struct rb_node* n) {
	struct rb_node* p = parent(n);
	struct rb_node* g = grandparent(n);
	if (g == NULL)
		return NULL; // No grandparent means no uncle
	return sibling(p);
}

void rotate_left(struct rb_node* n) {
	struct rb_node* nnew = n->right;
	struct rb_node* p = parent(n);
	
	assert(nnew != LEAF); // since the leaves of a red-black tree are empty, they cannot become internal nodes
	n->right = nnew->left; 
	nnew->left = n;
	n->parent = nnew;
	// handle other child/parent pointers
	if (n->right != NULL)
		n->right->parent = n;
	if (p != NULL) { // initially n could be the root
		if (n == p->left)
			p->left = nnew;
		else if (n == p->right) // if (...) is excessive
			p->right = nnew;
	}
	nnew->parent = p;
}

void rotate_right(struct rb_node* n) {
	struct rb_node* nnew = n->left;
	struct rb_node* p = parent(n);

	assert(nnew != LEAF); // since the leaves of a red-black tree are empty, they cannot become internal nodes
	n->left = nnew->right;
	nnew->right = n;
	n->parent = nnew;
	// handle other child/parent pointers
	if (n->left != NULL)
	n->left->parent = n;
	if (p != NULL) {// initially n could be the root
		if (n == p->left)
			p->left = nnew;
		else if (n == p->right) // if (...) is excessive
			p->right = nnew;
	}
	nnew->parent = p;
}

struct rb_node *insert(struct rb_node* root, struct rb_node* n) {
	// insert new node into the current tree
	insert_recurse(root, n);

	// repair the tree in case any of the red-black properties have been violated
	insert_repair_tree(n);

	// find the new root to return
	root = n;
	while (parent(root) != NULL)
		root = parent(root);
	return root;
}

void insert_recurse(struct rb_node* root, struct rb_node* n) {
	// recursively descend the tree until a leaf is found
	if (root != NULL && n->element < root->element) {
		if (root->left != LEAF) {
			insert_recurse(root->left, n);
   			return;
  		} 
		else
			root->left = n;
	} else if (root != NULL) {
		if (root->right != LEAF){
			insert_recurse(root->right, n);
			return;
		}
		else
			root->right = n;
	}

	// insert new node n
	n->parent = root;
	n->left = LEAF;
	n->right = LEAF;
	n->color = RED;
}

void insert_case4step2(struct rb_node* n)
{
	struct rb_node* p = parent(n);
	struct rb_node* g = grandparent(n);

	if (n == p->left)
		rotate_right(g);
	else
		rotate_left(g);
	p->color = BLACK;
	g->color = RED;
}

void insert_case4(struct rb_node* n) {
	struct rb_node* p = parent(n);
	struct rb_node* g = grandparent(n);

	if (n == p->right && p == g->left) {
		rotate_left(p);
		n = n->left;
	} else if (n == p->left && p == g->right) {
		rotate_right(p);
		n = n->right; 
	}
	insert_case4step2(n);
}

void insert_repair_tree(struct rb_node* n) {
	if (parent(n) == NULL) {
		if (!parent(n))
			n->color = BLACK;
	} else if (parent(n)->color == BLACK) {
		return;
	} else if (uncle(n) != NULL && uncle(n)->color == RED) {
		parent(n)->color = BLACK;
		uncle(n)->color = BLACK;
		grandparent(n)->color = RED;
		insert_repair_tree(grandparent(n));
	} else {
		insert_case4(n);
	}
}

void bt_insert_node(rb_tree* root, int data) {
	rb_tree *temp,*last;

	temp = root;
	for (temp=root;temp!=NULL;) {
		last = temp;
		temp = (data<=temp->element)?temp->left:temp->right;
	}

	temp = (rb_tree*)malloc(sizeof(struct rb_node));
	temp->element = data;

	if (temp->element<=last->element)
		last->left = temp;
	else
		last->right = temp;
}

void bt_delete_tree(rb_tree* root) {
	if (!root)
		return;
	if (root->left)
		bt_delete_tree(root->left);
	if (root->right)
		bt_delete_tree(root->right);
	free(root);
}

int main(int argc, char* argv[]) {
	rb_tree *root,*rb_root,*temp;

	root = (rb_tree*)malloc(sizeof(struct rb_node));
	memset(root,0,sizeof(struct rb_node));
	root->element = tree_data[0];
	
	for (int i=1;i<TREE_DATA_SIZE;i++) {
		bt_insert_node(root,tree_data[i]);
	}

	rb_root = NULL;
	for (int i=0;i<TREE_DATA_SIZE;i++) {
		temp = (rb_tree*)malloc(sizeof(struct rb_node));
		temp->element = tree_data[i];	
		rb_root = insert(rb_root,temp);
	}

	
	print_ascii_tree((Tree*)root);
	print_ascii_tree((Tree*)rb_root);

	bt_delete_tree(root);
	bt_delete_tree(rb_root);
	return 0;
}
