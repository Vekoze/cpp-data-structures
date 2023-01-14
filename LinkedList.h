#pragma once

#include <iostream>

template<class T>
class Node {
public:
	Node(T value) : value_(value), next_(nullptr) {};
	T Value() const { return value_; };
	Node*& Next() { return next_; }
private:
	T value_;
	Node* next_;
};

template<class T>
class LinkedList {
public:
	LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {};
	bool IsEmpty() const { return head_ == nullptr; }
	void PushBack(T value) {
		Node<T>* node = new Node(value);
		if (IsEmpty()) {
			head_ = node;
			tail_ = head_;
		}
		else {
			tail_->Next() = node;
			tail_ = node;
		}
	}
	void PushFront(T value) {
		Node<T>* node = new Node(value);
		node->Next() = head_;
		head_ = node;
	}
	T Pop() {
		if (head_ == nullptr) {
			throw std::out_of_range("LinkedList is empty.");
		}
		Node<T>* prev = head_;
		while (prev->Next() != tail_) {
			prev = prev->Next();
		}
		T value = tail_->Value();
		delete tail_;
		tail_ = prev;
		tail_->Next() = nullptr;
		return value;
	}
	friend std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
		os << "LinkedList: " << '\n';
		if (ll.head_ == nullptr) {
			os << "Empty" << '\n';
			return os;
		}
		Node<T>* current = ll.head_;
		while (current != nullptr) {
			os << current->Value() << " -> ";
			current = current->Next();
		}
		os << "null";
		return os;
	}

private:
	Node<T>* head_;
	Node<T>* tail_;
	int size_;
};