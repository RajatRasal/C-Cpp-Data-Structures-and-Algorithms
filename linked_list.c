#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list* list;
typedef struct node* node;
// typedef int /*nodeType*/int;

struct list {
  struct node *header;
  struct node *footer;
};

struct node {
  int key;
  struct node *prev;
  struct node *next;
};

node node_malloc(void) {
  printf("sizeof(struct node): %lu\n", sizeof(struct node));
  node n = malloc(sizeof(struct node));
  printf("sizeof(struct node): %lu\n", sizeof(struct node));
  if (n == NULL) {
    perror("node_malloc");
    exit(EXIT_FAILURE);
  }
  return n;
}

void init_list(struct list *l) {
  printf("here\n");
  l->header = node_malloc();
  printf("here\n");
  l->footer = node_malloc();
  l->header->prev = NULL;
  l->footer->next = NULL;
  l->header->next = l->footer;
  l->footer->prev = l->header;
}

node get_header(struct list *l) {
  return l->header; //next();
}

node get_footer(struct list *l) {
  return l->footer;
}

node next(struct node *n) {
  return n->next;
}

node prev(struct node *n) {
  return next(n);
}

int get_node_key(struct node *n) {
  return n->key;
}

void set_node_key(struct node *n, int x) {
  n->key = x;
}

bool is_not_termination(struct node *n) {
  return prev(n) != NULL && next(n) != NULL;
}

// void delete(list l, ) {

void free_node(struct node *n) {
  free(n);
}

void free_list(struct list *l) {
  node first = get_header(l);
  node nxt = next(first); // ->next;
  while (nxt != NULL) {
    free_node(first);
    first = nxt;
    nxt = next(nxt); //->next;
  }
  free_node(nxt);
}

void add(struct list *l, int x) {
  node n = get_footer(l);
  printf("here\n");
  n->prev->next = node_malloc();
  printf("1\n");
  // next(prev(n)) = malloc(sizeof(struct node));
  set_node_key(n->prev->next, x);
  printf("2\n");
  // prev(n)->get_node_key(next) = x;
  n->prev = n->prev->next;
  // n->prev = next(prev(n)); //n->prev->next;
  printf("3\n");
  // prev(n) = prev(n)next();
};

node find(struct list *l, /*nodeType*/int x) {
  node curr = get_header(l);
  while (curr != NULL) {
    curr = curr->next; 
    int y = get_node_key(curr);
    if (y == x) {
      return curr;
    }
  }
  return NULL;
}

void printAll(struct list *l) {
  node curr = get_header(l);
  while (curr != NULL) {
    curr = curr->next;
    char buff[12]; 
    if (curr != NULL) {
      sprintf(buff, "%d -> ", curr->key);
    } else {
      sprintf(buff, "%s", "NULL");
    }
    printf("%s", buff);
  }
  printf("\n");
}

int main(void) {
  printf("defdefdwse\n"); //, x);
  struct list example;
  printf("defdefdwse\n"); //, x);
  init_list(&example);
  // int x = get_node_key(get_header(&example));
  //init_list(example);
  printf("add\n");
  add(&example, 5);
  add(&example, 10);
  add(&example, 2);
  add(&example, 15);
  find(&example, 10);
  printAll(&example);
  // find(&example, 15);
  // find(&example, 2);
  free_list(&example);
}
