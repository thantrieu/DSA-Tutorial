#include<iostream>
using namespace std;
#define N 11

/*	Dùng đệ quy kiểm tra một dãy đã sắp xếp hay chưa

	**Giả sử cần kiểm tra dãy tăng dần
	- Bắt đầu tại vị trí pos = 0 lần lượt kiểm tra hai phần tử tại vị trí pos và pos + 1;
	- Điều kiện dừng:
		+ Nếu kiểm tra đến vị trí cuối mảng: pos == N-1 thì return true;
		+ Nếu trong quá trình kiểm tra mà phát hiện hai phần tử liền kề ko thỏa đk 
		  sắp xếp thì return false;
	- Nếu hai phần tử liền kề thỏa mãn đk, tiếp tục đệ quy lên vị trí pos + 1
*/

bool isSorted(int arr[], int pos) {
	if (pos == N - 1) {
		return true;
	}
	else {
		if (arr[pos] > arr[pos + 1]) {
			return false;
		}
		else {
			return isSorted(arr, pos + 1);
		}
	}
}


int main() {

	int arr[] = { 0, 1, 2, 3, 3, 4, 5, 6, 1, 8, 9 };

	bool result = isSorted(arr, 0);
	cout << result << endl;

	return 0;
}
