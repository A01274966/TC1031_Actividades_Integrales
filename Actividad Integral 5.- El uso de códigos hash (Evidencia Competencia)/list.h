#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T> class List;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
class List {
public:
	List();
  void clear();
	~List();

  bool empty() const;
  string toString() const;

  void addFirst(T);
	void add(T);

private:
	Link<T> *head;
	int 	size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
string List<T>::toString() const {
	stringstream aux;
	Link<T> *p;
	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value.get_numero();
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
void List<T>::addFirst(T val) {
	Link<T> *newLink;

	newLink = new Link<T>(val);

	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::add(T val) {
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);

	if (empty()) {
    addFirst(val);
    return;
	}

	p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
}

#endif