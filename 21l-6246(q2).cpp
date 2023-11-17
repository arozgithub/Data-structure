#include<iostream>
using namespace std;
static int SIZE = 10;
class queue;
class node {
	friend class queue;
	int data;
	node* next;

};
class queue {
	node* front;
	node* rear;
	int currqsize;
	
public:
	queue() {
		front = NULL;
		rear = NULL;
		currqsize = 0;

	}
	int size() {//timecomplexity=1
		return currqsize;
	}
	//int size() {
	//	int count = 0;
	//	node* curr = front;
	//	if (front != NULL) {
	//		if (curr->next == front) {
	//			return count++;
	//		}
	//		else {

	//			int count = 1;
	//			node* curr = front;
	//			while (curr->next != front) {
	//				count++;
	//				curr = curr->next;
	//			}
	//			return count;

	//		}

	//	}
	//	else return 0;
	//}
	bool isempty() {//timecomplexity=1
		if (front == NULL) {
			return true;
		}
		else return false;
	}
	bool frontvalue(int& x) {//timecomplexity=1
		if (isempty()) {
			return false;
		}
		else {
			x = front->data;
			return true;
		}
		
	}
	void enqueue(const int& e) {//timecomplexity=constant
		if (size() == SIZE) {
			cout << "queue is full\n";
		}
		node* temp = new node;
		temp->data = e;
		temp->next = NULL;
		if (isempty()) {
			front = temp;
			rear = temp;
			currqsize++;
			
		}
		else {
			rear -> next = temp;
			rear = temp;
			rear->next = front;
			currqsize++;
			
		}
	}
	void dequeue() {//timecomplexity=constant
		if (isempty()) {
			cout << "Queue is empty, exiting\n";
		}
		else if (front == rear) {
			delete front;
			delete rear;
			front = rear = NULL;
			currqsize--;
		}
		else {
			node* temp = front;
			front = front->next;
			rear->next = front;
			delete temp;
			currqsize--;
		}
			
		
	}
	void display() {//timecomplexity=n
		if (isempty()) {
			cout << "queue is empty";
		}
		else {
			node* curr = front;
			while (curr->next != front) {
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << curr->data;
		}
	}

};

int main(){
queue A;
int x = 0;

if (A.isempty()) {
	cout << "empty"<<endl;

}
	A.enqueue( 3);

	A.enqueue(5);

	A.enqueue(2);
	
	
	if (A.isempty()) {
		cout << "Empt";
	}
	A.enqueue(5);
	A.enqueue(6);
	A.display();
	cout << endl;
	cout << "size:" << A.size() << endl;
	A.frontvalue(x);
	cout<<"front value:" << x << endl;
	A.enqueue(9);
	A.dequeue();
	A.dequeue();
	A.display();

}
