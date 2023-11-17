#include <iostream>
using namespace std;

template<typename T>
class singlyLinkedList;

template<typename T>
class Node
{
	T data;
	Node* next;
	friend class singlyLinkedList<T>;
public:
	Node<T>() {
		this->next = NULL;
	}
};

template<typename T>
class singlyLinkedList {
	Node<T>* head;
public:
	singlyLinkedList() {
		head = nullptr;
	}

	//Insert at start 
	void insertatstart(T val) {
		Node<T>* new_node = new Node<T>;
		new_node->data = val;
		new_node->next = head;
		head = new_node;
	}

	//Insert at end 
	void insertatend(T val) {
		Node<T>* new_node = new Node<T>;
		new_node->data = val;
		new_node->next = NULL;
		Node<T>* prev = 0, * curr = head;
		while (curr != NULL) {
			prev = curr; curr = curr->next;
		}
		// if the element is first
		if (prev == 0) {
			head = new_node;
		}
		else {
			prev->next = new_node;
		}
	}

	//Print 
	void display() {
		Node<T>* curr = head;
		do {
			cout << curr->data << "->";
			curr = curr->next;
		} while (curr != NULL);
		cout << endl;
	}
	//Delete at Start 
	void deleteatstart() {
		if (head == NULL)
			;
		else {
			Node<T>* curr = head;
			head = curr->next;
			delete curr;
			curr = 0;
		}
	}
	//Delete at End 
	void deleteatend() {
		if (head == 0) {
			cout << "List is empty\n";
		}
		else {
			Node<T>* curr = head, * last = 0, * secondLast = 0;
			while (curr != NULL) {
				secondLast = last;
				last = curr;
				curr = curr->next;
			}
			if (secondLast == 0) {
				head = NULL;
				delete	last;
				last = 0;
			}
			else {
				secondLast->next = NULL;
				delete last;
				last = 0;
			}
		}
	}

	bool sortedInsert(T val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		Node* curr = head, * prev = 0;
		while (curr != NULL && curr->data < val)
		{
			prev = curr;
			curr = curr->next;
		}
		if (prev == 0)
		{
			head = temp;
		}
		else
		{
			prev->next = temp;
		}
		temp->next = curr;
		cout << "Element is inserted in Sorted Linked List...!\n";
		return 1;
	}

	//Distructor
	~singlyLinkedList() {
		while (head != NULL) {
			Node<T>* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}

	void printNth(int N) {
		int len = 0;
		Node<T>* temp = head;

		// Count the number of nodes in Linked List
		while (temp->next != NULL) {
			temp = temp->next;
			len++;
		}

		// Check if value of N is not
		// more than length of the linked list
		if (len < N)
			return;
		else {
			temp = head;

			// Get the (len-N+1)th node from the beginning
			for (int i = 1; i < len-N+1; i++) {
				temp = temp->next;
			}
			cout << temp->data << endl;;
			return;

		}
	}

};

int main()
{
	singlyLinkedList <int>l1;
	l1.insertatstart(2);
	l1.insertatstart(6);
	l1.insertatstart(7);
	//l1.insertatend(3);
	//l1.insertatend(8);
	//l1.insertatend(1);
	/*l1.deleteatstart();
	l1.deleteatend();*/
	l1.printNth(1);
	l1.display();
	cout << endl;

	return 0;
}