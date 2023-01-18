#pragma once

#include <iostream>

template<class T>
class Node {
public:
	Node() = delete;
	Node(const Node& node) = delete;
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
	LinkedList(const LinkedList<T>& ll) = delete;
	~LinkedList() {
		Node<T>* current = head_;
		while (current != nullptr) {
			Node<T>* temp = current;
			current = current->Next();
			delete temp;
		}
	}

	bool IsEmpty() const { return head_ == nullptr; }

	int Size() const { return size_; }

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
		size_++;
	}

	void PushFront(T value) {
		Node<T>* node = new Node(value);
		node->Next() = head_;
		head_ = node;
		size_++;
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
		size_--;
		return value;
	}

	friend std::ostream& operator<<(std::ostream& os, const LinkedList& ll) {
		os << "-----" << '\n';
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
		os << "null" << '\n';
		os << "-----";
		return os;
	}

private:
	Node<T>* head_;
	Node<T>* tail_;
	int size_;
};