#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct list {
  struct node *header;
  struct node *footer;
};

typedef struct list* list;
typedef struct node* node;
typedef int nodeType;

struct node {
  nodeType val;
  struct node *prev;
  struct node *next;
};

node node_malloc(void) {
  struct node *n = malloc(sizeof(struct node));
  if (n == NULL) {
    perror("node_malloc");
    exit(EXIT_FAILURE);
  }
  return n;
}

void node_free(node n) {
  free(n);
}

void init_list(list l) {
  l->header = node_malloc();
  l->footer = node_malloc();
  l->header->prev = l->footer; // NULL;
  l->footer->next = l->footer; // NULL;
  l->header->next = l->footer;
  l->footer->prev = l->header;
}

node get_header(list l) {
  return l->header; //next();
}

node get_footer(list l) {
  return l->footer;
}

node next(node n) {
  return n->next;
}

node prev(node n) {
  return next(n);
}

nodeType get_node_value(node n) {
  return n->val;
}

void set_node_value(node n, nodeType x) {
	n->val = x;
}

bool is_not_termination(node n) {
  return prev(n) != NULL && next(n) != NULL;
}

// void delete(list l, ) {

void free_list(list l) {
  node first = get_header(l);
	node nxt = next(first); //curr->next;
	while (nxt != NULL) {
		node_free(first);
		first = nxt;
	}
	free(nxt);
}

void add(list l, nodeType x) {
  node n = get_footer(l);
	printf("here\n");
	n->prev->next = node_malloc();
	printf("there\n");
	// next(prev(n)) = malloc(sizeof(struct node));
	set_node_value(n->prev->next, x);
	// prev(n)->get_node_value(next) = x;
	n->prev = next(prev(n)); //n->prev->next;
	// prev(n) = prev(n)next();
};

// void remove;
node find(list l, nodeType x) {
  node curr = get_header(l);
	// printf("header: %d\n", get_node_value(curr));
	while (curr != NULL) {
	  curr = next(curr);	
		printf("val: %d\n", get_node_value(curr));
		if (get_node_value(curr) == x) {
			// printf("FOUND\n");
		  return curr;
		}
	}
	return NULL;
}

int main(void) {
  struct list example;
  init_list(&example);	
	int x = get_node_value(get_header(&example));
	printf("header x : %d\n", x);
  add(&example, 5);
  add(&example, 10);
  add(&example, 2);
  // add(&example, 15);
	find(&example, 15);
	find(&example, 2);
	free_list(&example);
}
