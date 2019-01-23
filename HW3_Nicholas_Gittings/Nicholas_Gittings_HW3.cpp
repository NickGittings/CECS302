#include <iostream>
#include <string>
#include <queue>
#include <math.h>
#include <stack>
using namespace std;

//Create structure for nodes
struct BinaryNode {
	int data;
	BinaryNode * left = nullptr;
	BinaryNode * right = nullptr;
};

class BST {
private:
	BinaryNode * r;

public:

	BST(){
		r = nullptr;
	}

	BinaryNode* getRoot() {
		return this->r;
	}

	/*---------------Function Definitions---------------*/
	//Function to print tree taking BinaryNode root parameter O(logN)
	void printTree() {

		if(r == nullptr) {
			cout << "No tree" << endl;
		}
		else {
			queue<BinaryNode*> q;
			q.push(r);

			while(!q.empty()) {

				BinaryNode * n = q.front();
				q.pop();

				cout << n->data << endl;
				if(n->left != nullptr) q.push(n->left);
				if(n->right != nullptr) q.push(n->right);
			}
		}
	}

	//Inserts node down the tree in the next spot O(logN)
	void insertNode(int input) {

		queue<BinaryNode*> q;
		BinaryNode * newNode = new BinaryNode;
		newNode->data = input;

		if(r == nullptr) r = newNode;

		else {

			q.push(r);

			while(!q.empty()) {

				BinaryNode * n = q.front();
				q.pop();

				if(r->data == newNode->data) cout << "Node already exists" << endl;
				if(newNode->data < n->data) {
					if(n->left != nullptr) q.push(n->left);
					else newNode->parent = n, n->left = newNode, cout << "Inserted left" << endl;
				}

				else if(newNode->data > n->data)
					if(n->right != nullptr) q.push(n->right);
					else newNode->parent = n, n->right = newNode, cout << "Inserted right" << endl;
				else {
						while(n->left != nullptr) n = n->left, q.push(n);
						while(n->right != nullptr) n = n->right, q.push(n);
				}
			}
		}
	}

	//Returns number of nodes in tree O(logN)
	int returnNodes() {
		int counter;

		if(r == nullptr) {
			cout << "No tree" << endl;
		}
		else {
			queue<BinaryNode*> q;
			q.push(r);

			while(!q.empty()) {

				BinaryNode * n = q.front();
				q.pop();

				counter++;
				if(n->left != nullptr) q.push(n->left);
				if(n->right != nullptr) q.push(n->right);
			}
		}

		return counter;
	}

	//Returns number of leaves in tree O(logN)
	int returnLeaves() {
		double counter = 0.0;

		queue<BinaryNode*> q;
		q.push(r);

		if(r == nullptr) {
			cout << "No tree" << endl;
		}
		else {
			queue<BinaryNode*> q;
			q.push(r);

			while(!q.empty()) {

				BinaryNode * n = q.front();
				q.pop();

				counter += 0.5;
				if(n->left != nullptr) q.push(n->left);
				if(n->right != nullptr) q.push(n->right);
			}
		}

		//Uses modulus to see if counter has .5 and if so it rounds it up 1
		if(fmod(counter, 1.0) == 0.5) {
			counter + 0.5;
		}

		return counter;
	}

	//Returns number of full nodes in tree O(logN)
	int returnFullNodes() {
		int counter = 0;

		queue<BinaryNode*> q;
		q.push(r);

		if(r == nullptr) {
			cout << "No tree" << endl;
		}
		else {
			queue<BinaryNode*> q;
			q.push(r);

			while(!q.empty()) {

				BinaryNode * n = q.front();
				q.pop();

				if(n->data) counter++;
				if(n->left != nullptr) q.push(n->left);
				if(n->right != nullptr) q.push(n->right);
			}
		}

		return counter;
	}

};

//Iterator to go through binary search tree
class BSTiterator {
public:
	stack<BinaryNode*> stk;

	//Constructor which takes BST object and inserts nodes into it
	BSTiterator(BST tree) {

		BinaryNode * root = tree.getRoot();
		while(root != nullptr) {
			stk.push(root);
			root = root->left;
		}
		root = tree.getRoot();
		while(root != nullptr) {
			root = root->right;
		}
	}

		//Returns true if stack isn't empty
		bool begin() {
			if(!stk.empty()) return true;
			else return false;
		}

		//Returns true if stack is empty;
		bool end() {
			if(stk.empty()) return true;
			else return false;
		}

		//Pops stack
		void operator++(int) {
			stk.pop();
		}

		//Returns data of node
		int operator*() {
			int data = stk.top()->data;
			return data;
		}

};

//Client to test
int main(void) {
	BST tree;
	bool running = true;
	char choice;
	int input;

	while(running) {
		cout << "HW3 Client" << endl << "1. Add node" << endl << "2. Print tree" << endl;
		cout << "3. Exit" << endl << "Number of Nodes: " << tree.returnNodes() << endl << "Number of leaves: " << tree.returnLeaves() << endl << "Number of full nodes: " << tree.returnFullNodes() << endl;
		cin >> choice, cout << endl;
		switch (choice) {

			case '1':
				cout << "Enter integer: " << endl;
				cin >> input;
				tree.insertNode(input);
				break;

			case '2':
				tree.printTree();
				break;

			case '3':
				running = false;
				break;
		}
	}

	return 0;
}
