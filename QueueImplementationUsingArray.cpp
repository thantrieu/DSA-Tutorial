#include<iostream>
#include<string>
using namespace std;

const int SIZEMAX = 10;
int rear = -1; // giam sat dang chen den phan tu co chi so nao
int front = 0; // kiem soat dang thao tac toi phan tu nao cua queue
int itemCount = 0;// so phan tu hien thoi cua queue
int queue[SIZEMAX];

bool isEmpty() {
	return itemCount == 0;
}

bool isFull() {
	return itemCount == SIZEMAX;
}

int enQueue(int data) {// rear = 0-> rear = SIZEMAX - 1
	if (!isFull()) {
		if (rear == SIZEMAX - 1) {
			rear - 1;
		}
		rear++;
		itemCount++;
		queue[rear] = data;
		return 1; // success
	}
	else {
		return 0;// failed
	}
}

int peek() {
	if (!isEmpty()) {
		return queue[front];
	}
	else {
		return 0;// queue rong
	}
}

int deQueue() {
	if (!isEmpty()) {
		int data = queue[front];
		itemCount--;
		front++;
		if (front == SIZEMAX) {
			front = 0;
		}
		return data;
	}
	else {
		return 0;// queue rong
	}
}

int main() {
	enQueue(10);
	enQueue(100);
	enQueue(1000);
	enQueue(10000);
	enQueue(100000);
	enQueue(999999);
	cout << "QUEUE rong? " << isEmpty() << endl;
	cout << "QUEUE day? " << isFull() << endl;

	cout << "Fist Element Of QUEUE ? " << peek() << endl;

	while (!isEmpty()) {
		int data = peek();
		deQueue();
		cout << " " << data << endl;
	}

	cout << "QUEUE rong? " << isEmpty() << endl;
	cout << "QUEUE day? " << isFull() << endl;

	return 0;
}