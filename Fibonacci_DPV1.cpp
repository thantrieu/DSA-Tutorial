
/* Giải thuật quy hoạch động top-down tìm số fibonacci thứ n */

/*
					fibo(4)
				   /       \
			  fibo(3)	  fibo(2)
			  /	  \			 /	\
		fibo(2)	fibo(1)	fibo(1)  fibo(0)
		 /  \
	fibo(1)  fibo(0)
*/

#include<iostream>
#include<string>
using namespace std;

unsigned long long tmp[200];

void init() {
	for (int i = 0; i < 200; i++) {
		tmp[i] = -1;
	}
}

unsigned long long fiboQHD(int n) {
	if (tmp[n] == -1){
		if (n <= 1) {
			tmp[n] = n;
		}
		else {
			tmp[n] = fiboQHD(n - 1) + fiboQHD(n - 2);
		}
	}
	return tmp[n];
}

int main() {
	init();
	cout<< fiboQHD(100) << endl;
	return 0;
}