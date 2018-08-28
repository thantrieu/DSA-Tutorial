#include<iostream>
#include<string>
using namespace std;

void swap(int *a, int *b) {
	int x = *a;
	*a = *b;
	*b = x;
}

void selectionSort(int arr[], int n) {// thuat toan sap xep chon
	int min_index = 0;
	for (int i = 0; i < n - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		swap(&arr[i], &arr[min_index]);
	}
}

void output(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 2,3,6,5,4,0,1,9,8,7,5,2,13,2,5,4,2,1,3,0,2,0,6, -9, -99, -999 };
	int length = sizeof(arr) / sizeof(int);
	selectionSort(arr, length);
	output(arr, length);

	return 0;
}