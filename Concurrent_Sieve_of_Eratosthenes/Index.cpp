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

bool Index::search(int key){
	lock.lock();
	Node* cur = head;

	while (cur){
		if (cur->getItem() == key){
	    lock.unlock();
			return true;
		}
		cur = cur->getNext();
	}

	lock.unlock();
	return false;
}

bool Index::insert(int key){
	lock.lock();

	if (head == NULL){
		head = tail = new Node(key);
	  lock.unlock();
		return true;
	}

	Node* cur = head;

	while (cur->getNext()){
		cur = cur->getNext();
	}

	Node* item = new Node(key);
	cur->setNext(item);
	item->setPrev(cur);
	tail = item;
	lock.unlock();
	return true;
}

bool Index::remove(int key){
	lock.lock();
	Node* cur = head;

	while (cur) {
		if (cur->getItem() == key) {
			if (cur == tail && cur == head) {
				head = NULL;
				tail = NULL;
			} else if (cur == head) {
				head = cur->getNext();
				head->setPrev(NULL);
			} else if (cur == tail) {
				tail = cur->getPrev();
				tail->setNext(NULL);
			} else {
			  cur->getPrev()->setNext(cur->getNext());
			  cur->getNext()->setPrev(cur->getPrev());
			}
			lock.unlock();
			return true;
		}
		cur = cur->getNext();
	}

	lock.unlock();
	return false;
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




