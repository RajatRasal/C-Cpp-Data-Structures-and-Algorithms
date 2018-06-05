#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct doubly_linked_list* doubly_linked_list;
typedef struct node* node;

struct doubly_linked_list {
  struct node *header;
  struct node *footer;
};

struct node {
  int key;
  struct node *prev;
  struct node *next;
};

static node node_malloc(void) {
  node n = malloc(sizeof(struct node));
  if (n == NULL) {
    perror("node_malloc");
    exit(EXIT_FAILURE);
  }
  return n;
}

void init_doubly_linked_list(struct doubly_linked_list *l) {
  l->header = node_malloc();
  l->footer = node_malloc();
  l->header->prev = NULL;
  l->footer->next = NULL;
  l->header->next = l->footer;
  l->footer->prev = l->header;
}

static node get_header(struct doubly_linked_list *l) {
  return l->header; 
}

static node get_footer(struct doubly_linked_list *l) {
  return l->footer;
}

static node next(struct node *n) {
  return n->next;
}

static node prev(struct node *n) {
  return next(n);
}

static int get_node_key(struct node *n) {
  return n->key;
}

static void set_node_key(struct node *n, int x) {
  n->key = x;
}

static void free_node(struct node *n) {
  free(n);
}

void free_doubly_linked_list(struct doubly_linked_list *l) {
  node first = get_header(l);
  node nxt = next(first); 
  while (nxt != NULL) {
    free_node(first);
    first = nxt;
    nxt = next(nxt); 
  }
  free_node(nxt);
}

void add(struct doubly_linked_list *l, int x) {
  node n = get_footer(l);
  node tmp = node_malloc();
  set_node_key(tmp, x);
  tmp->next = n;
  tmp->prev = n->prev;
  n->prev->next = tmp;
  n->prev = tmp;
};

node find(struct doubly_linked_list *l, int x) {
  node curr = get_header(l)->next;
  while (curr != NULL) {
    int y = get_node_key(curr);
    if (y == x) {
      return curr;
    }
    curr = curr->next; 
  }
  return NULL;
}

void delete(struct doubly_linked_list *l, int x) {
  printf("%p\n", find(l,x));
  struct node *toDelete = find(l, x);
  //printf("toDelete key: %d\n", toDelete->key);
  // struct node **toDeletePtr = &toDelete;
  // find returns header or footer
  if (toDelete != NULL) {
    //printf("1\n");
    //printf("toDelete->prev->next->key: %d\n", toDelete->prev->next->key);
    toDelete->prev->next = toDelete->next;
    //printf("1\n");
    //printf("toDelete->next->prev->key: %d\n", toDelete->next->prev->key);
    toDelete->next->prev = toDelete->prev;
    //printf("1\n");
    free_node(toDelete);
  } else {
    printf("NULL\n");
  }
/*
  struct node *tmp = toDelete->prev;
  struct node *tmp2 = toDelete->next;
  printf("1\n");
  toDelete->next->prev = tmp;
  printf("1\n");
  tmp = toDelete->next;
  printf("1\n");
  toDelete->prev->next = tmp2;
*/
  // printf("%d\n", toDelete->prev->key);
/*
  printf("%d\n", toDelete->next->key);
  printf("%d\n", toDelete->next->prev->key);
  printf("%d\n", toDelete->prev->next->key);
*/
/*
  toDelete->next->prev = toDelete->prev;
  toDelete->prev->next = toDelete->next;
*/
}

void printList(struct doubly_linked_list *l) {
  node curr = get_header(l)->next;
  printf("NULL <-> ");
  while (curr != NULL) {
    char buff[12]; 
    if (curr->next != NULL) {
      sprintf(buff, "%d <-> ", curr->key);
    } else {
      sprintf(buff, "%s", "NULL");
    }
    curr = curr->next;
    printf("%s", buff);
  }
  printf("\n");
}

int main(void) {
  struct doubly_linked_list example;
  init_doubly_linked_list(&example);
  add(&example, 5);
  add(&example, 10);
  add(&example, 2);
  add(&example, 15);
  add(&example, 120);
  find(&example, 10);
  printList(&example);
  delete(&example, 10);
  delete(&example, 120);
  delete(&example, 1);
  printList(&example);
  free_doubly_linked_list(&example);
}
