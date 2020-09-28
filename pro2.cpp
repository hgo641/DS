#include <iostream>
#include <cstdlib>
#include<ctime>
using namespace std;
class node {
public:
	node(int data);
	int data;
	node* next;
};
node::node(int data) {
	this->data = data;
	this->next = NULL;
}
class linkedlist {
public:
	node* f;
	node* r;
	linkedlist();
	int front();
	int end();
	void addend(int data);
	int removefront();
};
linkedlist::linkedlist() {
	this->f = NULL;
	this->r= NULL;
}
int linkedlist::front() {
	return f->data;
}
int linkedlist::end() {
	return r->data;
}
void linkedlist::addend(int data) {
	node* newnode = new node(data);
	if (f == NULL) {
		f = r = newnode;
	}
	else {
		r->next = newnode;
		r = newnode;
	}
}
int linkedlist::removefront() {
	if (f != NULL) {
		node* tmp = f;
		cout << f->data << endl;
		int tmp_int = f->data;
		f = f->next;
		delete tmp;
		return tmp_int;
	}
	return -1;
}
class linkedqueue {
public:
	linkedlist* S;
	int n;
	linkedqueue();
	int size();
	int isEmpty();
	int front();
	int rear();
	void enqueue(int e);
	void dequeue();
};
linkedqueue::linkedqueue() {
	this->S = new linkedlist();
	this->n = 0;

}
int linkedqueue::size() {
	return n;
}
int linkedqueue::isEmpty() {
	if (n == 0)return 1;
	else return 0;
}
int linkedqueue::front() {
	if (isEmpty() == true) cout << "Empty" << endl;
	else return S->front();
}
int linkedqueue::rear() {
	if (isEmpty() == true) cout << "Empty" << endl;
	else return S->end();
}
void linkedqueue::enqueue(int e) {
	n++;
	S->addend(e);
}
void linkedqueue::dequeue() {
	if (isEmpty() == true) cout << "Empty" << endl;
	else {
		S->removefront();
		n--;
	}
}
int main() {
	
}
