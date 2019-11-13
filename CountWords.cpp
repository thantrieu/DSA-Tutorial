#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct Node {
	string data;
	int counter;
	Node* left;
	Node* right;
};

typedef Node* Tree;

Node* createNode(string data) {
	Node* p = new Node();
	p->data = data;
	p->counter = 1;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void addNode(Tree& t, Node* p) {
	if (t != NULL) {
		if (t->data.compare(p->data) == 0) {
			t->counter++; // tang bien dem
		}
		else if (t->data.compare(p->data) > 0) {
			addNode(t->left, p); // chen trai
		}
		else {
			addNode(t->right, p); // chen phai
		}
	}
	else {
		t = p;
	}
}

void showNode(Tree t) {
	if(t != NULL) {
		showNode(t->left);
		cout << left << setw(12) << t->data << ": " << t->counter << endl;
		showNode(t->right);
	}
}

void readData(Tree& t) {
	ifstream ifs("words.txt");
	while (!ifs.eof()) {
		string word;
		ifs >> word;
		Node* p = createNode(word);
		addNode(t, p);
	}
	ifs.close();
}

int main() {
	Tree t = NULL;
	readData(t);
	showNode(t);

	return 0;
}