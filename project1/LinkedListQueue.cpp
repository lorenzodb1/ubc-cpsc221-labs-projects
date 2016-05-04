//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
  // TODO:  Initialize any member variables as needed in the constructor.
	head = tail = NULL;
	size = 0;
}

void LinkedListQueue::add(MazeState *elem)
{
  // TODO:  Implement this.
	if (is_empty()) {
		node* temp = new node;
		temp->data = elem;
		head = temp;
		tail = head;
		size++;
	}
	else {
		node* temp = new node;
		temp->data = elem;
		tail->next = temp;
		tail = temp;
		size++;
	}
}

MazeState *LinkedListQueue::remove()
{
	// TODO:  Implement this.
	assert(!is_empty());
	MazeState *val = head->data;
	node* temp = head;
	head = head->next;
	delete temp;
	size--;
	return val;
}

bool LinkedListQueue::is_empty()
{
  // TODO:  Implement this.
	return size == 0;
}

LinkedListQueue::~LinkedListQueue()
{
  // TODO:  Implement the destructor.  Be sure to delete everything.
	while (!is_empty()) {
		remove();
	}
}

#endif

