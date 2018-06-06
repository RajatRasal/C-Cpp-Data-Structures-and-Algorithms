#include <stdio.h>
#include <string.h>
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
  node first = l->header;
  node nxt = first->next; 
  while (nxt != NULL) {
    free_node(first);
    first = nxt;
    nxt = nxt->next; 
  }
  free_node(nxt);
}

void add(struct doubly_linked_list *l, int x) {
  node n = l->footer;
  node tmp = node_malloc();
  set_node_key(tmp, x);
  tmp->next = n;
  tmp->prev = n->prev;
  n->prev->next = tmp;
  n->prev = tmp;
};

node find(struct doubly_linked_list *l, int x) {
  node curr = l->header->next;
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
  // printf("%p\n", find(l,x));
  struct node *toDelete = find(l, x);
  if (toDelete != NULL) {
    if (memcmp(toDelete, l->header, sizeof(struct node)) == 0 
        || memcmp(toDelete, l->footer, sizeof(struct node)) == 0) {
      printf("THIS IS BEING DETECTED\n");
      return;
    } else {
      toDelete->prev->next = toDelete->next;
      toDelete->next->prev = toDelete->prev;
      free_node(toDelete);
    }
  } else {
    printf("NULL\n");
  }
}

void printList(struct doubly_linked_list *l) {
  node curr = l->header->next;
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
  delete(&example, 0);
  delete(&example, 5);
  add(&example, 5);
  add(&example, 10);
  add(&example, 2);
  add(&example, 15);
  add(&example, 0);
  add(&example, 120);
  find(&example, 10);
  printList(&example);
  delete(&example, 10);
  delete(&example, 120);
  delete(&example, 1);
  delete(&example, 0);
  printList(&example);
  delete(&example, 15);
  delete(&example, 5);
  delete(&example, 2);
  printList(&example);
  delete(&example, 0);
  free_doubly_linked_list(&example);
}
