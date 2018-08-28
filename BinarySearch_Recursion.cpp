#include<iostream>
#include<string>
using namespace std;

void swap(int *a, int *b) {
	int x = *a;
	*a = *b;
	*b = x;
}

int partion(int arr[], int l, int h) {
	int p = arr[h];
	int i = l - 1;// bien giam sat qua trinh thuc hien sap xep
	for (int j = l; j < h; j++) {
		if (arr[j] < p) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	// tim dc vi tri chinh xac cua ptu cam canh
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

void quickSort(int arr[], int l, int h) {
	if (l < h) {
		int pi = partion(arr, l, h);
		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, h);
	}
}

void output(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

/* Binary search using recursion */
int binarySearch(int arr[], int l, int h, int x) {
	if (l <= h) {
		int m = l + (h - l) / 2;
		if (arr[m] == x) {// tim thay
			return m;
		}

		if (arr[m] < x) {
			return binarySearch(arr, m + 1, h, x);
		}
		else {
			return binarySearch(arr, l, m - 1, x);
		}
	}

	return -1;
}

int main() {
	int arr[] = { 2,3,6,5,4,0,1,9,8,7,5,2,13,2,5,4,2,1,3,0,2,0,6 };
	int length = sizeof(arr) / sizeof(int);
	quickSort(arr, 0, length - 1);
	output(arr, length);
	int x = 6;
	int index = binarySearch(arr, 0, length - 1, x);
	if (index != -1) {
		cout << "Ton tai gia tri " << x << endl;
	}
	else {
		cout << "Khong ton tai gia tri " << x << endl;
	}
	return 0;
}