// C++ implementation of
// the Quadratic Probing
#include <iostream>
using namespace std;

// Function to print an array
void printArray(int arr[], int n)
{
	// Iterating and printing the array
	for (int i = 0; i < n; i++) {
		cout << i<<" "<<arr[i] << endl;
	}
}

// Function to implement the
// quadratic probing
void hashing(int table[], int tsize, int arr[], int N)
{
	// Iterating through the array
	for (int i = 0; i < N; i++) {
		// Computing the hash value
		int hv = arr[i] % tsize;

		// Insert in the table if there
		// is no collision
		if (table[hv] == -1)
			table[hv] = arr[i];
		else {
			// If there is a collision
			// iterating through all
			// possible quadratic values
			for (int j = 1; j < tsize; j++) {
				// Computing the new hash value
				int t = (hv + j*j ) % tsize;
				if (table[t] == -1) {
					// Break the loop after
					// inserting the value
					// in the table
					table[t] = arr[i];
					break;
				}
			}
		}
	}
	printArray(table, N);
}

// Driver code
int main()
{
	int arr[] = { 5,15,30,25,6,16 };
	int N = 10;

	// Size of the hash table
	int L = 10;
	int hash_table[10];

	// Initializing the hash table
	for (int i = 0; i < L; i++) {
		hash_table[i] = -1;
	}

	// Function call
	hashing(hash_table, L, arr, N);
	return 0;
}

