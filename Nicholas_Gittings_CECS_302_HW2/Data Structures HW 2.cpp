#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct Node{
	int data;
	Node * next;
};

class linkedlist {
private:
	Node * head;
	Node * tail;

public:

	linkedlist() {
		head = nullptr;
		tail = nullptr;
	}

	void createNode(int n) {
		Node * newNode = new Node;
		newNode->data = n;
		newNode->next = nullptr;

		//If head is , set head and tail equal to newNode
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
			newNode = nullptr;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	//Goes through list and stores integer values in a list container which is then printed with an iterator
	void print_reverse() {
		Node * temp = new Node;
		list<int> reverse;
		temp = head;
		while (temp != nullptr) {
			int i = temp->data;
			reverse.push_front(i);
			temp = temp->next;
		}
		for (auto it = reverse.begin(); it != reverse.end(); it++) {
			cout << *it << ", ";
		}
		cout << endl;

	}
};

class stack {
private:
	Node * top;

public:
	stack() {
		top = nullptr;
	}

	//Creates newNode, stores integer, sets next pointer to top, and sets top to newNode
	void push(int n){

			Node * newNode = new Node;
			newNode->data = n;
			newNode->next = top;
			top = newNode;

	}

	//Removes node from top of stack
	void pop() {
		if (top == nullptr) {
			cout << "No top" << endl;
		}
		else {
			top = top->next;
		}
	}

	//Reads the top of the stack
	void read() {
		if (top == nullptr) {
			cout << "Top is empty" << endl;
		}
		else {
			cout << "Value: " << top->data << endl << "Pointer: " << top->next << endl;
		}
		
	}

};

//Function prototype
void intersection(list<int> list1, list<int> list2);

int main()
{
	//Create stack and linkedlist objects
	stack stk;
	linkedlist linked;

	//Creates two lists
	list<int> first = { 0,2,5,7,8,13, 16 };
	list<int> second = { 0,1,3,7,9,10,12,13,15, 16 };

	//Finds intersection of the two lists above ^^^
	intersection(first, second);

	//While loop menu for adding and viewing nodes to stack/list
	bool running = true;
	int choose, n;
	while (running) {

		cout << "1. Add node" << endl;
		cout << "2. Read top node" << endl;
		cout << "3. Pop node" << endl;
		cout << "4. Add node to linked list" << endl;
		cout << "5. Print linked list in reverse" << endl;
		cout << "6. Exit" << endl;
		cin >> choose;

		switch (choose) {
		case 1:
			cout << "Enter an integer: " << endl;
			cin >> n;
			stk.push(n);
			break;

		case 2:
			stk.read();
			break;

		case 3:
			stk.pop();
			break;

		case 4:
			cout << "Enter an integer: " << endl;
			cin >> n;
			linked.createNode(n);
			break;

		case 5:
			linked.print_reverse();
			break;

		case 6:
			running = false;
			break;

		default: 
			cout << "Wrong input" << endl;
			break;
		}
	}

	return 0;
}

//Function to find same values in list using iterators
void intersection(list<int> list1, list<int> list2) {

	for(auto it = list1.begin(); it != list1.end(); it++) {

		for (auto it2 = list2.begin(); it2 != list2.end(); it2++) {

			if (*it == *it2) {
				
				cout << "Intersection at: " << *it << endl;

			}
		}
	}

}