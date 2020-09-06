#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList() {
	this->length = 0;
	this->head = nullptr;
	this->tail = nullptr;
}

SinglyLinkedList::~SinglyLinkedList() {
	Node* cur = this->head;
	while (cur) {
		Node* temp = cur->next;
		delete cur;
		cur = temp;
	}
}

int SinglyLinkedList::push(int val) {
	Node* node = new Node(val);
	if (!this->head) {
		this->head = node;
		this->tail = this->head;
	} else {
		this->tail->next = node;
		this->tail = node;
	}
	return ++this->length;
}

int SinglyLinkedList::pop() {
	if (this->length == 0) return -1;
	
	int tempVal{-1};
	if (this->head != this->tail) {
		Node* newTail = this->getNode(this->length - 2);
		tempVal = newTail->next->val;
		delete newTail->next;
		newTail->next = nullptr;
		this->tail = newTail;
	} else {
		tempVal = this->head->val;
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
	}
	this->length--;
	return tempVal;
}

int SinglyLinkedList::unshift(int val) {
	if (!this->head) return this->push(val);
	Node* node = new Node(val);
	node->next = this->head;
	this->head = node;
	return ++this->length;
}

int SinglyLinkedList::shift() {
	if (!this->head) return -1;
	Node* temp = this->head;
	int tempVal = temp->val;
	this->head = temp->next;
	delete temp;
	this->length--;
	return tempVal;
}

int SinglyLinkedList::insert(int index, int val) {
	if (index < 0 || index > this->length) return -1;
	else {
		if (index == 0) return this->unshift(val);
		else if (index == this->length) return this->push(val);
		else {
			Node* n1 = this->getNode(index - 1);
			Node* n2 = this->getNode(index);
			Node* n = new Node(val);
			n1->next = n;
			n->next = n2;
			return ++this->length;
		}
	}
}

int SinglyLinkedList::remove(int index) {
	if (index < 0 || index > this->length - 1) return -1;
	else {
		if (index == 0) return this->shift();
		else if (index == this->length - 1) return this->pop();
		else {
			Node* n = this->getNode(index - 1);
			Node* temp = this->getNode(index);
			int tempVal = temp->val;
			n->next = temp->next;
			delete temp;
			this->length--;
			return tempVal;
		}
	}
}

Node* SinglyLinkedList::getNode(int index) {
	int i = 0;
	Node* cur = this->head;
	while (cur && i != index) {
		cur = cur->next;
		i++;
	}
	return cur;
}

int SinglyLinkedList::get(int index) {
	if (index >= 0 && index < this->length) {
		return this->getNode(index)->val;
	}
	return -1;
}

int SinglyLinkedList::size() {
	return this->length;
}

void SinglyLinkedList::reverse() {
	Node* cur = this->head;
	Node* temp = nullptr;
	Node* prev = nullptr;
	while (cur) {
		temp = cur;
		cur = cur->next;
		temp->next = prev;
		prev = temp;
	}
	this->tail = this->head;
	this->head = temp;
}

int* SinglyLinkedList::toArray(int* existingArr) {
	
	//Cleaning up existing space.
	if (existingArr) delete[] existingArr;

	//Checking for empty list.
	if (this->length == 0) return nullptr;
	
	//Creating newArr on heap.
	int* newArr = new int[this->length];
	Node* cur = this->head;
	int count = 0;
	while (cur && count < this->length) {
		newArr[count] = cur->val;
		cur = cur->next;
		count++;
	}
	return newArr;
}







