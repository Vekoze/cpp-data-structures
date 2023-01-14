#include <iostream>
#include "LinkedList.h"

int main() {

	// LinkedList
	LinkedList<int> ll;
	std::cout << "empty:" << std::boolalpha << ll.IsEmpty() << '\n';
	ll.PushBack(3);
	ll.PushBack(4);
	ll.PushBack(5);
	ll.PushFront(2);
	ll.PushFront(1);
	std::cout << ll << '\n';
	std::cout << "pop: " << ll.Pop() << '\n';
	std::cout << ll << '\n';

	return 0;
}