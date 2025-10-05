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
		if (head->next == nullptr) {
			head = nullptr;
			return;
		}
		if (head->next == tail) {
			head->next->prev = nullptr;
			head = head->next;

			tail = nullptr;
			head->next = nullptr;

			return;
		}
		head->next->prev = nullptr;
		head = head->next;


	}

	void pop_back() {
		if (tail == nullptr) {
			head = nullptr;
			return;
		}
		if (tail->prev == head) {
			tail = nullptr;
			head->next = nullptr;
			return;
		}
		tail->prev->next = nullptr;
		tail = tail->prev;
	}
	
	void bubble_sort() {
		if (head == nullptr || head->next == nullptr)
		{
			std::cout << "Not sort" << std::endl;
			return;
		}

		int count = 0;
		Node* tmpCount = head;
		while (tmpCount != nullptr) {
			count++;
			tmpCount = tmpCount->next;
		}

		for (int i = 0; i < count - 1; i++) {
			Node* tmp = head;
			bool swapped = false;

			while (tmp->next != nullptr) {
				if (tmp->data > tmp->next->data) {
					Node* first = tmp;
					Node* second = tmp->next;

					first->next = second->next;
					second->prev = first->prev;

					if (second->next != nullptr)
						second->next->prev = first;

					if (first->prev != nullptr)
						first->prev->next = second;

					second->next = first;
					first->prev = second;

					if (head == first)
						head = second;
					if (first->next == nullptr)
						tail = first;

					swapped = true;
				}
				else {
					tmp = tmp->next; 
				}
			}

			if (!swapped) break; 
		}
	}

	void display_list() {
		Node* tmp = head;

		if (tmp == nullptr) {
			std::cout << "list empty" << std::endl;
			return;
		}

		while (tmp->next != nullptr) {
			std::cout << tmp->data << std::endl;
			tmp = tmp->next;
		}
		std::cout << tail->data << std::endl;
	}

	void remove_duplicates() {

		Node* tmp = head;
		Node* next = head->next;

		if (head == nullptr || head->next == nullptr) {
			std::cout << "Not delete" << std::endl;
			return;
		}


		while (next != nullptr) {
			if (tmp->data == next->data) {
				tmp->next = next->next;
				if (next->next != nullptr)
					next->next->prev = tmp;

				next = nullptr;
				next = tmp->next;
			}
			else {
				tmp = next;
				next = next->next;
			}
		}

		tail = tmp;
	}
};



int main()
{
	DoublyLinkedList list = {};

	short action;

	while (true) {
		std::cout << "Enter action" << std::endl;
		std::cout << "1 - add element in front" << std::endl;
		std::cout << "2 - add element in back" << std::endl;
		std::cout << "3 - delete element in front" << std::endl;
		std::cout << "4 - delete element in back" << std::endl;
		std::cout << "5 - display list" << std::endl;
		std::cout << "6 - sort list" << std::endl;
		std::cout << "7 - delete duplicates" << std::endl;
		std::cout << "8 - exit" << std::endl;



		switch (action) {
			case 1:
				std::cout << "enter element" << std::endl;
				short n;
				std::cin >> n;
				list.push_front(n);
				break;

			case 2: 
				std::cout << "enter element" << std::endl;
				short n;
				std::cin >> n;
				list.push_back(n);
				break;
			case 3:
				list.pop_front();
				break;
			case 4: 
				list.pop_back();
				break;
			case 5:
				list.display_list();
				break;
			case 6:
				list.bubble_sort();
				break;
			case 7:
				list.remove_duplicates();
				break;
			default:
				return 0;
		}

	}

	//list.push_back(1);	


	//list.push_back(3);
	//list.push_back(1);

	//list.push_front(7);

	//list.push_back(3);
	//list.push_back(1);

	//list.bubble_sort();

	//list.remove_duplicates();

	//list.display_list();

	return 0;
}

