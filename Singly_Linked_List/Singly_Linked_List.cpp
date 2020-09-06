#include <iostream>
#include "SinglyLinkedList.h"

void printArr(int* arr, int length);

int main() {
	SinglyLinkedList list;
	list.push(10);
	list.push(12);
	list.push(78);
	list.push(73);
	list.push(17);

	int* arr = list.toArray();
	printArr(arr, list.size());

	list.reverse();
	
	arr = list.toArray(arr);
	printArr(arr, list.size());

	delete[] arr;
}

void printArr(int* arr, int length) {
	std::cout << "\n[";
	for (int i = 0; i < length; i++) {
		i == (length - 1) ? std::cout << arr[i] : std::cout << arr[i] << "  ";
	}
	std::cout << "]\n";
}

