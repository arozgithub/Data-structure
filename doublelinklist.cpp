#include<iostream>
using namespace std;
class doublylinkedlist;
class node {
	int data;
	node* next;
	node* prev;
	friend class doublylinkedlist;
};
class doublylinkedlist {
	node* head;
public:
	doublylinkedlist() {
		head = nullptr;
	}
	bool insertatstart(int val) {
		node* temp = new node;
		temp->data = val;
		temp->prev = NULL;
		head->prev = temp;
		temp->next = head;
		head = temp;
		return 1;

	}
	bool deletefromstart() {
		if (head == 0) {
			return 0;

		}
		else {
			node* curr = head;
			head = curr->next;
			delete curr;
			curr = 0;
			return 1;
		}
	}
	void display() {
		node* curr = head;
		while (curr != 0) {
			cout << curr->data << ",";
			curr = curr->next;

		}
	}
	bool insertatend(int val) {
		node* temp = new node;
		temp->data = val;
		temp->next = NULL;
		temp->prev = NULL;
		node* curr = head;
	
		while (curr->next != NULL) {

			curr = curr->next;

		}
		if (head == NULL) {
			head = temp;
			return 1;
		}
		else {
			curr->next = temp;
			temp->prev = curr;                                                      
			return 1;
		}
		
	}
	bool deletefromend() {
		if (head == 0) {
			cout << "list is empty" << endl;
			return 0;
		}
		else {

			node* curr = head;
			while (curr->next != 0) {
				curr = curr->next;

			}
			curr->prev->next = NULL;
			delete curr;
			curr = 0;
			cout << "last block deleted:" << endl;
			return 1;
		}
			

		
	}

	~doublylinkedlist() {
		node* curr = head;
		while (head != NULL) {
			head = curr->next;
			delete curr;
			curr = head;
		}
	}
	node* search(int val) {
		node* curr = head;
		if (head == NULL) {
			cout << "not possible search" << endl;
			return 0;
		}
		else {
			while (curr != NULL) {
				if (curr->data == val) {
					return curr;
				}
				curr = curr->next;
			}
		}
	}
	bool deletespecific_value(int val) {
		node* curr = head;
		if (head == NULL) {
			cout << "not possible";
			return 0;
		}
		else {
			if (curr->next == NULL && curr->data == val) {
				return curr;
			}

			while (curr != NULL) {
				if (curr->data == val) {
					if (curr == head) {
						head = curr->next;
						delete curr;
						curr = 0;
						return 1;
					}
					curr->prev->next = curr->next;
					
					delete curr;
					curr = 0;
					return 1;
				}
				curr = curr->next;
			}
		}
	}
	bool sortedinsert(int val) {
		node* temp = new node;

		temp->data = val;
		temp->prev = NULL;
		node* curr = head;

		if (head == NULL) {
			head = temp;
			temp->next = NULL;
			return 0;
		}

		if (head->data >= temp->data) {
			head->prev = temp;
			temp->next = head;
			head = temp;
			return 1;
		}

		while (curr != NULL) {
			if (curr->data >= temp->data) {
				curr->prev->next = temp;
				temp->prev = curr->prev;
				curr->prev = temp;
				temp->next = curr;
				break;
			}
			else if (curr->next == NULL) {
				curr->next = temp;
				temp->prev = curr;
				break;
			}
			curr = curr->next;
		}



	}

};
int main() {
	doublylinkedlist l1;
	l1.insertatstart(2);
	l1.insertatstart(6);
	l1.insertatstart(7);
	l1.insertatend(3);
	l1.insertatend(8);
	l1.insertatend(1);
	l1.deletefromstart();
	l1.deletefromend();
	l1.deletespecific_value(6);
	node*result=l1.search(3);
	cout << "search :";
		cout << result << endl;
	l1.sortedinsert(4);
	l1.sortedinsert(9);
	l1.sortedinsert(3);
	l1.display();
	cout << endl;

}