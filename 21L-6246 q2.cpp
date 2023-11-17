#include<iostream>

using namespace std;
class linkedList;
class node
{
	friend class linkedList;
	int data;
	node* next;
};
class linkedList
{

private:



	node* tail, * head;

public:

	linkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void addNodeAtStart(int n)
	{
		node* temp = new node;
		temp->data = n;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head = temp;
		}
	}

	void addNodeEnd(int n)
	{
		node* temp = new node;
		temp->data = n;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	node* getHead()
	{
		return head;
	}

	void print()
	{
		if (head != NULL)
		{
			node* temp = head;

			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		else
		{
			cout << "List is Empty\n";
		}

	}

	linkedList Union(linkedList A, linkedList B)
	{
		linkedList c;
		node* currc = c.head;
		node* currA = A.head;
		node* currB = B.head;
		while (currA != NULL) {
			c.addNodeEnd(currA->data);
			currA = currA->next;
		}


		while (currB != NULL) {
			c.addNodeEnd(currB->data);
			currB = currB->next;
		}

		return c;
	}

	linkedList intersection(linkedList& obj)//obj of A
	{
		linkedList D;
		//t is of current object B / head
		node* t = head;
		for (; t != NULL; t = t->next)
		{
			node* temp = obj.head;
			while (temp != NULL)
			{	//comparing B with A
				if (t->data == temp->data)
				{
					D.addNodeEnd(t->data);
					break;
				}
				temp = temp->next;
			}
		}

		return D;
	}

	linkedList sortList()
	{
		int x;
		cout << "Enter the number of elements ";
		cin >> x;
		int* arr = new int[x];
		for (int i = 0; i < x; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < x; i++)
		{
			for (int j = i + 1; j < x; j++)
			{
				if (arr[j] < arr[i])
				{
					int temp = arr[j];
					arr[j] = arr[i];
					arr[i] = temp;
				}
			}
		}

		linkedList E;

		for (int i = 0; i < x; i++)
		{
			E.addNodeEnd(arr[i]);
		}

		return E;
	}


};

int main()
{
	linkedList A;
	//enter elements of your own choice
	int* arr = new int[5];

	for (int i = 0; i < 5; i++) {
		cout << "enter values for A=";
		cin >> arr[i];
	}
	for (int i = 0; i < 5; i++) {
		A.addNodeEnd(arr[i]);
	}

	cout << "A List : \n";
	A.print();
	// can also do for B
	linkedList B;
	B.addNodeEnd(4);
	B.addNodeEnd(6);
	B.addNodeEnd(1);
	B.addNodeEnd(8);
	B.addNodeEnd(5);
	B.addNodeEnd(10);
	B.addNodeEnd(2);
	B.addNodeEnd(7);
	B.addNodeEnd(9);
	cout << "\nB List : \n";
	B.print();

	linkedList C;
	C = C.Union(A, B);
	cout << endl;
	cout << "\nUnion : \n";
	C.print();
	cout << endl;
	//another way as compared to union current object B/intersection
	linkedList D;
	D = B.intersection(A);
	cout << endl;
	cout << "Intersection : \n";
	D.print();
	cout << endl;

	linkedList E;
	E = E.sortList();
	cout << "\nArray after Sorting : \n";
	E.print();
	cout << endl;
	system("pause");
	return 0;
}