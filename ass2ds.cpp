#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;

template <typename k, typename v>
class MinHeap {
	//each item in heap will be HeapItem (a <key, value> pair). Both key and value can be of the same datatype or different data type.
	// Key and value can be of a user-defined class as well. If key is of non-primitive datatype, then the > and < operators must be overloaded.
	struct HeapItem {
		k key;
		v value;

		
	};

	HeapItem* arr;
	int capacity;
	int totalItems;

	void doubleCapacity()
	{
		if (this->arr == nullptr)
		{
			this->arr = new HeapItem[1];
			this->capacity = 1;
			return;
		}

		int newCapacity = capacity * 2;
		HeapItem* newArr = new HeapItem[newCapacity];

		for (int i = 0; i < this->totalItems; i++)
		{
			newArr[i] = this->arr[i];
		}

		if (this->arr != nullptr)
			delete[] this->arr;

		this->capacity = newCapacity;
		swap(arr, newArr);


	}

	void shiftUp(int index)
	{
		if (index < 1)
			return;

		int parent = (index - 1) / 2;

		if (this->arr[index].key < this->arr[parent].key)
		{
			swap(this->arr[index], this->arr[parent]);
			shiftUp(parent); //to compare with the parent after swaping
		}

		return;
	}

	void shiftDown(int index)
	{
		int minIndex = -1;
		int lChildIndex = index * 2 + 1;
		int rChildIndex = (index * 2) + 2;

		if (lChildIndex < totalItems)
		{
			if (arr[index].key > arr[lChildIndex].key)
			{
				minIndex = lChildIndex;
			}
		}

		if (rChildIndex < totalItems)
		{
			if (arr[(minIndex == -1 ? index : minIndex)].key > arr[rChildIndex].key)
			{
				minIndex = rChildIndex;
			}
		}

		if (minIndex == -1)
			return;

		swap(arr[index], arr[minIndex]);
		shiftDown(minIndex);


	}

public:
	MinHeap()
	{
		this->arr = nullptr;
		this->capacity = 0;
		this->totalItems = 0;
	}

	MinHeap(int _capacity)
	{
		assert(_capacity >= 1);

		this->arr = new HeapItem[_capacity];
		this->capacity = _capacity;
		this->totalItems = 0;
	}

	void insert(k const key, v const value)
	{
		if (totalItems == capacity)
			doubleCapacity();



		arr[totalItems].key = key;
		arr[totalItems].value = value;


		shiftUp(totalItems);
		totalItems++;



	}



	void getMin(v& value)
	{
		assert(totalItems != 0);

		value = arr[0].value;
	}

	void deleteMin() {
		assert(totalItems != 0);

		swap(arr[0], arr[totalItems - 1]);

		totalItems--;

		//shift down
		shiftDown(0);
	}

	bool isEmpty() const {
		return (totalItems == 0);
	}



	void deleteAll()
	{
		if (this->arr != nullptr)
		{
			delete[]arr;
			arr = nullptr;
			this->capacity = 0;
			this->totalItems = 0;
		}

	}

	~MinHeap()
	{
		deleteAll();
	}

};

class Student {
	int rollNumber;
	string name;
	float cgpa;

public:
	Student() {
		rollNumber = -1, name = "", cgpa = -1;
	}
	Student(int rollNumber, string name, float cgpa) {
		this->rollNumber = rollNumber, this->name = name, this->cgpa = cgpa;
	}

	//setters
	void setr(int roll) { this->rollNumber = roll; }
	void setn(string n) { this->name = n; }
	void setc(float c) { this->cgpa = c; }

	friend ostream& operator<<(ostream& out, const Student& s) {
		out << s.rollNumber << "\t" << s.name << "\t" << s.cgpa << "\n";
		return out;
	}

};

void buildStudentHeap(const string& fileName, MinHeap<int, Student>& stdHeap) {
	fstream fin(fileName, ios::in);
	if (!fin) {
		cout << "invalid file "; 
	return; }


	int rollNumber;
	string name;
	float cgpa;

	string temp;
	int t;

	fin >>t;
	getline(fin, temp); 
	Student* s = new Student[t];
	for (int i = 0; i < t; i++) {
		fin >> rollNumber >> name >> cgpa;
		s[i].setr(rollNumber);
		s[i].setn(name);
        s[i].setc(cgpa);
		stdHeap.insert(rollNumber, s[i]);
	}
	fin.close();

}

int main()
{
	MinHeap<int, Student> stdHeap;
	buildStudentHeap("students.txt", stdHeap);
	while (!stdHeap.isEmpty())
	{
		Student s;
		stdHeap.getMin(s);
		cout << s << endl << endl;
		stdHeap.deleteMin();
	}
	system("pause");
}