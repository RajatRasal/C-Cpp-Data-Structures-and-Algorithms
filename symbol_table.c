#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_LINE_LENGTH 513

// The constant values and hash function are taken from 
// Introduction to Algorithms, Stein et al.
// Size of the symbol table. Should be a prime number large
// enough to have good performance for medium size programs
static const uint32_t tableSize = 109;
// Processor wordsize
static const uint32_t wordSize = 32;
// A is a fraction of the form s/2^(wordSize) where s is an
// uint32_teger in the range 0 < s < 2^w. A is currently the fraction
// closest to (root(5) - 1)/2.
static const uint32_t s = 2654435769;

uint32_t hash(const char key[MAX_LINE_LENGTH]) {
  float A = s/pow(2, wordSize);
  uint32_t keyInt = 0;
  for (uint32_t i = 0; i < strlen(key); i++) {
		printf("%c ", key[i]);
    keyInt += (key[i] * i);
  }
	//printf("%u, %f\n", keyInt, keyInt * A);
  //float x = ((float) (A * keyInt) - (int) (A * keyInt));
	//printf("%f\n", x);
  return floor(tableSize * ((float) (A * keyInt) - (int) (A * keyInt)));
}

/* Node data structure. Many of these can be strung together to 
 * build up linked list */ 
typedef struct node {
  char label[MAX_LINE_LENGTH];
  uint32_t address;
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
  memset(n->label, '\0', sizeof(char)*MAX_LINE_LENGTH); 
	// printf("%s\n", n->label);
  return n;
}

node* init_linked_list(void) {
  return NULL;
}

/* Gets the key of a given node */
/*
static uint32_t get_node_key(node *n) {
  return n->key;
}
*/

/* Sets the key of a given node */
static void set_node_label_address(node *n, const char label[MAX_LINE_LENGTH], uint32_t address) {
	// n->label = label;
  strcpy(n->label, label); //, sizeof(char)*strlen(label)); 
	// printf("here: %s\n", n->label);
  n->address = address;
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
void push(node **head, const char label[MAX_LINE_LENGTH], uint32_t address) {
  node *n = node_malloc();
  set_node_label_address(n, label, address); 
  // n->key = key;
  // n->address = address;
  n->next = *head;
  *head = n;
}

/* Finds a node with a particular key in the linked list */
uint32_t find(node *head, const char label[MAX_LINE_LENGTH]) {
  node *curr = head;
  while (curr != NULL) { 
    if (memcmp(curr->label, label, MAX_LINE_LENGTH) == 0) {
      return (curr->address);
    }
    curr = curr->next;
  }
  return -1;
}

/* Deletes a node with a particular key from the linked list
void delete(node **head, char label[MAX_LINE_LENGTH]) {
  // Checks the list isn't empty when we are deleting from it
  if (*head != NULL) {
    // Case for when the node to be deleted is at the head
    if ((*head)->address == address) {
      free(*head);
      *head = (*head)->next;
      return;
    }
    node *prev = *head;
    node *curr = (*head)->next;
    while (curr != NULL) {
      if (curr->address == address) {
        free(curr);
        prev->next = curr->next;
        return;
      }
      prev = curr;
      curr = curr->next;
    }
  }
}
*/

node **init_sym_table(void) {
  node **symTable = malloc(sizeof(node*) * tableSize); 
  return symTable;
}

void free_sym_table(node** sym_table) {
  for (uint32_t i; i < tableSize; i++) {
    free_linked_list(sym_table[i]);
  }
  free(sym_table); 
}

void add_to_sym_table(node** sym_table, char label[MAX_LINE_LENGTH], uint32_t address) {
  uint32_t bucket = hash(label);
  push(&sym_table[bucket], label, address);
}

uint32_t find_in_sym_table(node** sym_table, char label[MAX_LINE_LENGTH], uint32_t address) {
  uint32_t bucket = hash(label);
  return find(sym_table[bucket], label);
}

void print_linked_list(node *head) {
  node *curr = head;
  while (curr != NULL) {
    printf("(label: %s, addr: %u) -> ", curr->label, curr->address);
    curr = curr->next;
  }
  printf("NULL\n");
}

void print_sym_table(node **sym_table) {
  for (uint32_t i = 0; i < tableSize; i++) {
    printf("bucket: %u -> ", i); 
    print_linked_list(sym_table[i]);
  } 
}

int main(void) {
  /*
  node *head = init_linked_list();
  push(&head, "label1", 0x30000000);
  push(&head, "label2", 0x30000000);
  push(&head, "label3", 0x30000000);
  printf("head: %d, %s\n", head->address, head->label);
  print_linked_list(head);
  */
  node **sym_table = init_sym_table();
  // printf("%u\n", hash("label1"));
  uint32_t bucket = hash("label1");
  uint32_t bucket2 = hash("label2");
	printf("%u %u\n", bucket, bucket2);
  sym_table[bucket] = init_linked_list();
  //push(&sym_table[bucket], "label1", 0x30000000);
  //push(&sym_table[bucket2], "label2", 0x30000000);
  //print_linked_list(sym_table[bucket]);
  add_to_sym_table(sym_table, "label1", 0x30000000);
  add_to_sym_table(sym_table, "label2", 0x30100000);
	/*
	*/

  print_sym_table(sym_table);
  free_sym_table(sym_table);
}
