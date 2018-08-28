#include<iostream>
#include<string>
using namespace std;

void swap(int *a, int *b) {
	int x = *a;
	*a = *b;
	*b = x;
}

void bubbleSort1(int arr[], int n) {// noi ptu nho nhat len truoc
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				swap(&arr[j], &arr[j - 1]);
			}
		}
	}
}

void bubbleSort2(int arr[], int n) {// noi ptu lon nhat len truoc
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void output(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = { 2,3,6,5,4,0,1,9,8,7,5,2,13,2,5,4,2,1,3,0,2,0,6 };
	int length = sizeof(arr) / sizeof(int);
	bubbleSort2(arr, length);
	output(arr, length);

	return 0;
}