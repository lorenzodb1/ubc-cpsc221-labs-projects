//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::add(MazeState *elem) {
	// TODO:  Implement this!
	int hole;
	heap.push_back(elem);
	hole = (int)heap.size() - 1;
	while ((heap[parent(hole)]->getBadness() > elem->getBadness())){
		std::swap(heap[parent(hole)], heap[hole]);
		hole = parent(hole);
	}
}

MazeState * HeapPriorityQueue::remove() {
	// TODO:  Implement this!
	assert(!is_empty());
	MazeState* temp = heap[0];
	int last = (int)heap.size();
	last = last - 1;
	heap[0] = heap[last];
	heap.pop_back();
	int i = 0;
	int left = first_child(i);
	int right = left + 1;
	int target;
	helper(i);
	return temp;
}

bool HeapPriorityQueue::is_empty() {
	// TODO:  Implement this!
	return (heap.size() == 0);
}

// You might find these helper functions helpful...
int HeapPriorityQueue::parent(int index) {
	return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
	return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
	return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
	return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
	int fchild = first_child(index);
	return max(0, min(2, (int)heap.size() - fchild));
}

void HeapPriorityQueue::helper(int n) {
	if (is_leaf(n)) return;
	int left = first_child(n);
	int right = left + 1;
	int target;
	if (num_children(n) == 1) {
		if (!heap[left]) {
			if (heap[right]->getBadness() < heap[n]->getBadness()) {
				std::swap(heap[right], heap[n]);
				right = (first_child(n)) + 1;
				helper(right);
			}
		}
		if (!heap[right]) {
			if (heap[left]->getBadness() < heap[n]->getBadness()) {
				std::swap(heap[left], heap[n]);
				n = first_child(n);
				helper(n);
			}
		}
	}
	else if (num_children(n) == 2) {
		if (heap[left]->getBadness() < heap[right]->getBadness()) {
			target = left;
		}
		else {
			target = right;
		}
		if (target == left) {
			if (heap[left]->getBadness() < heap[n]->getBadness()){
				std::swap(heap[left], heap[n]);
				n = first_child(n);
				helper(n);
			}
		}
		if (target == right) {
			if (heap[right]->getBadness() < heap[n]->getBadness()) {
				std::swap(heap[right], heap[n]);
				right = (first_child(n)) + 1;
				helper(right);
			}
		}
	}
}
#endif
