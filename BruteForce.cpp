/* Brute Force algorithm */

#include<iostream>
#include<string>
using namespace std;

int bruteForce(const char *des, const char *x, int n, int m) {
	/* des: dai n, x: dai m */
	int j = 0;
	int count = 0;
	for (int i = 0; i <= (n - m); i++) {
		for (j = 0; j < m && x[j] == des[i+j]; j++);
		if (j >= m) {
			count++;
		}
	}
	return count;
}

int main() {
	const char *des = "ABCCBACBABCABCA";

	const char *x = "B";

	int lenDes = strlen(des);
	int lenX = strlen(x);
	
	int res = bruteForce(des, x, lenDes, lenX);
	cout << "Xau x xuat hien: " << res  << " lan trong xau des."<< endl;
	return 0;
}