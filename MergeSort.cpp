
/* thuc thi thuat toan sap xep tron */

#include<iostream>
#include<string>
using namespace std;

void merge(int arr[], int l, int m, int h) {
	int i, j, k = l;
	int n1 = m - l + 1;
	int n2 = h - m;
	/*
		0 ... 7: 8 ptu
		m = 3
		n1 = 3- 0 +1 = 4
		n2 = 7- 3 = 4
	*/
	int *L = new int[n1];
	int *R = new int[n2];

	for (i = 0; i < n1; i++) {
		L[i] = arr[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[m + j + 1];
	}
	// tron
	i = 0; j = 0;
	while (i < n1 && j < n2) {
		arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	}

	while (i < n1) {
		arr[k++] = L[i++];
	}

	while (j < n2) {
		arr[k++] = R[j++];
		/* ar[k] = R[j]; k++; j++*/
	}
}

void mergeSort(int arr[], int l, int h) {// thuat toan sap xep tron
	/*
		1. tim phan tu middle
		2. de quy nua truoc cua mang
		3. de quy nua sau cua mang
		4. tron hai nua lai thanh mang ket qua
	*/
	if (l < h) {
		int m = l + (h - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, h);
		merge(arr, l, m, h);
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
	mergeSort(arr, 0, length-1);
	output(arr, length);

	return 0;
}