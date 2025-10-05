#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;

	Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};


class DoublyLinkedList {
public: 
	Node* head = nullptr;
	Node* tail = nullptr;

	void push_front(int n) {

		if (head == nullptr) {
			head = new Node(n);
			return;
		}
		if (tail == nullptr) {
			Node* tmp = new Node(n);
			tmp->next = head;
			tail = head;
			tail->prev = tmp;
			head = tmp;
			return;
		}
		Node* tmp = new Node(n);
		head->prev = tmp;
		tmp->next = head; 
		head = tmp;
	}

	void push_back(int n) {
		Node* tmp = new Node(n);
		if (head == nullptr) {
			head = new Node(n);
			return;
		}
		if(tail == nullptr){
			Node* tmp = new Node(n);
			tmp->prev = head;
			head->next = tmp;
			tail = tmp;
			return;
		}
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
	}
		
	void pop_front(){
		if (head != nullptr) {
			Node* tmp = head->next;
			head = tmp;
			if (head->next == nullptr) {
				tail = nullptr;
			}
		}
	}

	void pop_back() {

	}
};



int main()
{
	DoublyLinkedList list = {};

	list.push_back(1);	
	list.push_front(6);

	list.push_back(3);
	list.push_front(7);

	std::cout << list.head->data << std::endl;
	std::cout << list.tail->data << std::endl;
	return 0;
}

