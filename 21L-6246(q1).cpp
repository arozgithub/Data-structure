#include<iostream>
using namespace std;
class stack;
class node {
	friend class stack;
	int data;
	node* next;
	
};
class stack {
	node* top;
public:
	stack() {
		top = 0;
	}
	int size() {//timecomplexity=n
		if (top != NULL) {
			int count = 0;
			node* curr = top;
			while (curr != NULL) {
				count++;
				curr = curr->next;
			}
			return count;
		}
		else return 0;
	}
	bool isempty() {//timecomplexity=1
		if (top == NULL) {
			return true;
		}
		else return false;

	}
	bool TOP(int& temp) {//timecomplexity=1
		if (top == NULL) {
			return false;
		}
		else {
			temp = top->data;
			return true;
		}
	}
	void pop() {//timecomplexity=1
		if (top != NULL) {
			node* curr = top;
			top = top->next;
			delete curr;
			curr = 0;
		}
		else;
	}
	void push(int val) {//timecomplexity=1
		if (top == NULL) {
			node* temp = new node;
			temp->data = val;
			top = temp;
			top->next = NULL;

		}
		else {
			node* temp = new node;
			temp->data = val;
			temp->next = top;
			top = temp;
		}
	}
	void display() {//timecomplexity=n
		node* curr = NULL;
		curr = top;
		while (curr != NULL) {
			cout << curr->data;
			cout << endl;
			curr = curr->next;
		}
	}
	bool sort(stack a){//timecomplexity=n^2
			node* index1, * index2;
			for (index1 = top; index1->next != NULL; index1 = index1->next) {
				for (index2 = index1->next; index2 != NULL; index2 = index2->next) {
					if (index1->data > index2->data) {

						//swap
						int temp = index1->data;
						index1->data = index2->data;
						index2->data = temp;
					}
				}
			}
			return top;
		
	}
	bool delmid(stack a) {//timecomplexity=n
		if (top != NULL) {
			int s = size();
			if (s == 1) {
				cout << "not possible";
				return false;
			}
			s = s / 2;

			int i = 0;
			node* curr = a.top;
			node* prev = curr;

			while (i < s) {
				prev = curr;
				curr = curr->next;
				i++;
			}
			prev->next = curr->next;
			delete curr;
			curr = 0;
			return true;

		}
		return false;
	}
	void checksum(int k) {//timecomplexity=n^2
		if (top != NULL) {
			node* curr = top;

			while (curr != NULL) {
				node* temp = top->next;
				while (temp != NULL) {
					if ((curr->data) + (temp->data) == k) {
						cout << curr->data << "," << temp->data << endl;

					}
					temp = temp->next;
				}
				curr = curr->next;
			}
		}
	}
	bool palindrome() {//timecomplexity=n/2
		int s = size();
		if (s % 2 == 0) {
			cout << "not palindrome";
			return false;
		}
		else {
			s = s / 2;
			int i = 0, sum=0;
			node* curr = top;
			while (i < s) {
				sum += curr->data;
				curr = curr->next;
				i++;
			}

			curr = curr->next;
			int sum2 = 0;
			while (i < size()-1) {
				sum2 += curr->data;
				curr = curr->next;
				i++;
			}

			if (sum == sum2) {
				cout << "palindrome\n";
				return true;
			}
			else cout << "not palindrome"<<endl;
			return 0;


		}
	}
};

int main() {
	stack A;
	A.push(1);
	A.push(2);
	A.push(3);
	A.push(2);
	A.push(2);
	A.display();
	//A.delmid(A);
	//A.display();
	//A.checksum(17);
	A.palindrome();
	A.sort(A);
	A.display();
}
