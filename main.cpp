#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &A, int target) {
    // write your code here
        int size = A.size();
        if (size == 0)
          return 0;
        int left = 0;
        int right = size - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] > target) {
                right = mid;
            } else if (A[mid] < target) {
                left = mid;
            } else {
                return mid;
            }
	    cout << left << " " << right << endl;
        }
        if (A[left] == target)
          return left;
        if (A[right] == target)
          return right;
        if (A[left] > target)
          return left;
        if (A[right] > target)
          return right;
        return size;
}

int main() {
  vector<int> a = {1,3,5,6,8,9};
  cout << binarySearch(a, 7) << endl;
}
