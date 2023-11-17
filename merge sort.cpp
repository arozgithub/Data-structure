#include<iostream>
using namespace std;
void merge(int* arr, int l1, int l2, int r1, int r2);
void mergesort(int* arr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(arr, start, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, start, mid, mid + 1, end);
	}
}
void merge(int* arr, int l1, int l2, int r1, int r2) {
	int* temp = new int[r2 - l1 + 1];
	int i = l1, j = r1, k = 0;
	while (i <= l2 && j <= r2) {
		if (arr[i] < arr[j]) {
			temp[k] = arr[i];
			i++;
		}
		else {
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while (i <= l2) {
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= r2) {
		temp[k] = arr[j];
		j++;
		k++;
	}
	int start;
	for (start = l2, k = 0; start <= r2; start++, k++) {
		arr[start] = temp[k];
	}
	delete[]temp;
	temp = 0;
}
int main() {
	int n;
	cout << "input size"<<endl;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "enter value:" << endl;
		cin >> arr[i];

	}
	for (int i = 0; i < n; i++) {
		
		cout<< arr[i]<<" ";

	}
	mergesort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {

		cout << arr[i] << " ";

	}
}