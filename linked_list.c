#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Node data structure. Many of these can be strung together to 
 * build up linked list */ 
typedef struct node {
  int key;
  struct node *next;
} node;

/* Allocates memory for a single node. Returns the node which space
 * has been allocated for */
static node* node_malloc(void) {
  node* n = malloc(sizeof(struct node));
  if (n == NULL) {
    perror("node_malloc");
    exit(EXIT_FAILURE);
  }
  return n;
}

node* init_linked_list() {
  return NULL;
}

/* Gets the key of a given node */
static int get_node_key(node *n) {
  return n->key;
}

/* Sets the key of a given node */
static void set_node_key(node *n, int x) {
  n->key = x;
}

/* Frees a node which has already has space allocated to it */
static void free_node(node *n) {
  free(n);
}

/* Goes through each element in the linked list from the head
 * until the tail, which is NULL, and frees each node since 
 * each node has been malloced to begin with */ 
void free_linked_list(node *head) {
  node *nxt = head->next; 
  while (nxt != NULL) {
    free(head);
    head = nxt;
    nxt = nxt->next; 
  }
}

/* Adds a node to the front of the linked list */
void push(node **head, int key) {
  node *n = node_malloc();
  n->key = key;
  n->next = *head;
  *head = n;
}

/* Finds a node with a particular key in the linked list */
node *find(node *head, int key) {
  node *curr = head;
  while (curr != NULL) { 
    if (curr->key == key) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

/* Deletes a node with a particular key from the linked list */
void delete(node **head, int key) {
  /* Checks the list isn't empty when we are deleting from it */
  if (*head != NULL) {
    /* Case for when the node to be deleted is at the head */
    if ((*head)->key == key) {
      free(*head);
      *head = (*head)->next;
      return;
    }
    node *prev = *head;
    node *curr = (*head)->next;
    while (curr != NULL) {
      if (curr->key == key) {
        free(curr);
        prev->next = curr->next;
        return;
      }
      prev = curr;
      curr = curr->next;
    }
  }
}

void printList(node *head) {
  node *curr = head;
  while (curr != NULL) {
    printf("%d -> ", curr->key);
    curr = curr->next;
  }
  printf("NULL\n");
}

int main(void) {
  node *head = init_linked_list();
  push(&head, 5);
  push(&head, 6);
  push(&head, 7);
  printf("head: %d\n", head->key);
  printList(head);
  delete(&head, 5);
  delete(&head, 6);
  printList(head);
  delete(&head, 7);
  printList(head);
}
