#pragma once
#include "Node.h"

class SinglyLinkedList{

private:
	//Fields
	Node* head;
	Node* tail;
	int length;

	//Methods
	Node* getNode(int index);

public:
	SinglyLinkedList();
	~SinglyLinkedList();
	int push(int val);
	int pop();
	int unshift(int val);
	int shift();
	int insert(int index, int val);
	int remove(int index);
	int get(int index);
	int size();
	void reverse();
	int* toArray(int* existingArr = nullptr);

};

