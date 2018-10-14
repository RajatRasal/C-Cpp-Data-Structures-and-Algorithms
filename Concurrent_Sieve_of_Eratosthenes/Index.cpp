#include "Index.hpp"

using namespace std;

// Node class implementation

Node::Node(int i){
  item = i;
  prev = NULL;
  next = NULL;
}

Node* Node::getPrev(){
  return prev;
}

Node* Node::getNext(){
  return next;
}

int Node::getItem(){
  return item;
}

void Node::setPrev(Node* p){
  prev = p;
}

void Node::setNext(Node* n){
  next = n;
}

// Index class implementation

Index::Index(int seeds[], int length){
  head = NULL;
  tail = NULL;

  // insert the seed elements into the index
  for(int i=0; i<length; i++){
    bool ret = insert(seeds[i]);
  }
}

Node* Index::find(int key) {
	lock.lock();

	Node* cur = head;

	while (cur) {
		if (cur->getItem() == key) {
	    lock.unlock();
			return cur;
		}
		cur = cur->getNext();
	}

	lock.unlock();
	return NULL;
}

bool Index::search(int key) {
	return find(key);
}

bool Index::insert(int key) {
	Node* item = new Node(key);

	if (head == NULL) {
		head = tail = item;
	} else {
	  tail->setNext(item);
	  item->setPrev(tail);
	  tail = item;
	}

	return true;
}

bool Index::remove(int key) {
	// lock.lock();
	
	Node* node = find(key);

	if ((head == NULL && tail == NULL) || !node) {
		return false;
	} else if (node == tail && node == head) {
		head = NULL;
		tail = NULL;
	} else if (node == head) {
		head = node->getNext();
		head->setPrev(NULL);
	} else if (node == tail) {
		tail = node->getPrev();
		tail->setNext(NULL);
	} else {
	  node->getPrev()->setNext(node->getNext());
	  node->getNext()->setPrev(node->getPrev());
	}

	return true;
}

void Index::printIndex(char order) {

  Node* start;

  // configure traversal order
  if (order == '<') {
    start = head;
  } else if (order == '>') {
    start = tail;
  } else {
    cerr << "ERROR: unrecognised input order " << order << endl;
    return;
  } 
  
  Node* cur = NULL; 
  Node* nxt = start;
  cout << "|--";

  // traverse the index elements
  while (nxt != NULL) {

    if (nxt != start) {
      cout<< "<-->";
    } 

    cur = nxt;
    if (order == '<') {
      nxt = cur->getNext();
    } else {
      nxt = cur->getPrev();
    }
    
    cout << "|·|" << cur->getItem() << "|·|";
  }

  cout << "--|" << endl;
}




